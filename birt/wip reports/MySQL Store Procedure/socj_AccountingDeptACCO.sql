DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_AccountingDeptACCO` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_AccountingDeptACCO`(IN fromDate VARCHAR(50), IN toDate VARCHAR(50))
BEGIN
# The reason we are doing this is because of Dan KARSPERSKY's stupid BIRT not taking As name.
select UPPER(j.socj_coid) as COID, (e.department+0) as Department,
UPPER(rollup_group) as DepartmentGroup, UPPER(rollup_division) as DepartmentDivision, UPPER(department_name) as DepartmentName,
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
JOIN soc_extension e
ON j.socj_job = e.job and
   j.socj_phase = e.phase and
   j.socj_Date_effective = e.report_date and
   j.socj_coid = e.coid
# where clause to include currentx = X (This may be an issue)
JOIN dept_rollup r
ON e.department = r.department_number
and e.coid = r.coid
where #j.socj_job = 611227 and
j.socj_currentx = "X" and
j.socj_Date_effective = toDate AND j.socj_coid ="ACCO"
group by e.department ,j.socj_coid;

END $$

DELIMITER ;