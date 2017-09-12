DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_Branch` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_Branch`(IN fromDate VARCHAR(50), IN toDate VARCHAR(50), IN company VARCHAR(50))
BEGIN
select UPPER(e.branch_name) as BranchName, UPPER(e.vendor_name) as VendorName,
 #Booking
    sum(IFNULL(j.socj_RevEst_total,0)) - sum(IFNULL(p.socj_RevEst_total,0)) as Bookings,

#Backlogs
    sum(j.socj_RevEst_Total) - ((sum(j.socj_RevAct_billings) + sum(j.socj_Earn_exceed_bill)) -sum(j.socj_Bill_exceed_earn)) as Backlog,

#Revenue
(sum(IFNULL(j.socj_gp_curr_yr,0)) + sum(IFNULL(j.socj_gp_prior_yr,0)) + sum(IFNULL(j.socj_costact,0))) -
(sum(IFNULL(p.socj_gp_curr_yr,0)) + sum(IFNULL(p.socj_gp_prior_yr,0)) + sum(IFNULL(p.socj_costact,0))) as Revenue,

#profit
sum(IFNULL(j.socj_gp_curr_yr,0)) as Profit


From soc_journal j
#Join with last year data, use left join to include job that was not in last year but new for this year.
LEFT JOIN ( select * from soc_journal where socj_Date_effective = fromDate and socj_currentx ="X") p
ON j.socj_job = p.socj_job AND j.socj_coid = p.socj_coid
#Join with extension for extra info
JOIN soc_job_info_log e
ON j.socj_job = e.job and
   j.socj_phase = e.phase and
   j.socj_Date_effective = e.report_date and
   j.socj_run_time = e.run_time and
   j.socj_coid = e.coid
# where clause to include currentx = X (This may be an issue)
where #j.socj_job = 611227 and
j.socj_currentx = "X" and
j.socj_Date_effective = toDate AND j.socj_coid = company COLLATE latin1_general_cs
group by e.branch_name, e.vendor_name#, j.socj_coid# v, socj_job
order by e.branch_name, e.vendor_name;
END $$

DELIMITER ;