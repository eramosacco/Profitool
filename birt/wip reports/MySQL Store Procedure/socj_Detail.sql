DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_Detail` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_Detail`(IN fromDate VARCHAR(50), IN toDate VARCHAR(50),IN company VARCHAR(50))
BEGIN
select (j.socj_job+0) as job, (j.socj_phase+0) as phase, UPPER(l.name) as JobName,
l.department as CostDept, pm_clk, pm_name, pm_pct, pm_dept as pm_dept,
(IFNULL(j.socj_RevEst_Total,0) - IFNULL(s.socj_RevEst_Total,0)) * pm_pct/100 as Bookings,

(IFNULL(j.socj_revest_Total,0) - ((IFNULL(j.socj_RevAct_Billings,0) + IFNULL(j.socj_Earn_exceed_bill,0)) -IFNULL(j.socj_Bill_exceed_earn,0))) * pm_pct/100 as Backlog,
((IFNULL(j.socj_GP_curr_yr,0) + IFNULL(j.socj_GP_prior_yr,0) +IFNULL(j.socj_CostAct,0)) - ((IFNULL(s.socj_GP_curr_yr,0) + IFNULL(s.socj_GP_prior_yr,0) +IFNULL(s.socj_CostAct,0)))) * pm_pct/100 as Revenue,
j.socj_GP_curr_yr * pm_pct/100 as Profit

From soc_journal j

JOIN soc_job_info_log l
ON j.socj_job = l.job
and j.socj_phase = l.phase
and j.socj_coid = l.coid
and j.socj_date_effective = l.report_date
and j.socj_run_time = l.run_time


INNER JOIN soc_pm_info_log p
ON j.socj_job = p.job
AND j.socj_phase = p.phase
and j.socj_coid = p.coid
and j.socj_date_effective = p.report_date
and j.socj_run_time = p.run_time


LEFT JOIN ( select * from soc_journal where socj_Date_effective = fromDate and socj_currentx ="X") s
ON j.socj_job = s.socj_job AND j.socj_coid = s.socj_coid

WHERE j.socj_Date_effective = toDate and j.socj_coid = company COLLATE latin1_general_cs and p.report_date = toDate and
j.socj_currentx ="X"
order by pm_name, j.socj_job

;
END $$

DELIMITER ;