DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_DeptAdjDetailSimple` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_DeptAdjDetailSimple`(IN fromDate VARCHAR(50), IN toDate VARCHAR(50),IN company VARCHAR(50))
BEGIN
select (l.department+0) as AdjDept,"-->" as Direction,pm_dept as InFromOutTo, (j.socj_job +0) as job, (j.socj_phase+0) as phase, UPPER(l.name) as JobName,
(l.department+0) as CostDept, pm_clk, pm_name, pm_pct, pm_dept as pm_dept,
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

INNER JOIN soc_pm_info_log p
ON j.socj_job = p.job
AND j.socj_phase = p.phase
and j.socj_coid = p.coid
and j.socj_date_effective = p.report_date


LEFT JOIN ( select * from soc_journal where socj_Date_effective = fromDate and socj_currentx ="X") s
ON j.socj_job = s.socj_job AND j.socj_coid = s.socj_coid

WHERE j.socj_Date_effective = toDate and j.socj_coid = company COLLATE latin1_general_cs and p.report_date = toDate and
j.socj_currentx ="X" and l.department != pm_dept AND l.department between 60 and 69 and pm_dept between 60 and 99
and IF(l.department = 62 && p.pm_dept = 68,1,0)=0 and IF(l.department = 68 && p.pm_dept = 62,1,0)=0

UNION

select  pm_dept as AdjDept, "<--" as Direction , (l.department+0) as InFromOutTo,(j.socj_job +0) as job, (j.socj_phase+0) as phase, UPPER(l.name) as JobName,
(l.department+0) as CostDept, pm_clk, pm_name, pm_pct, pm_dept as pm_dept,
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

INNER JOIN soc_pm_info_log p
ON j.socj_job = p.job
AND j.socj_phase = p.phase
and j.socj_coid = p.coid
and j.socj_date_effective = p.report_date


LEFT JOIN ( select * from soc_journal where socj_Date_effective = fromDate and socj_currentx ="X") s
ON j.socj_job = s.socj_job AND j.socj_coid = s.socj_coid

WHERE j.socj_Date_effective = toDate and j.socj_coid = company COLLATE latin1_general_cs and p.report_date = toDate and
j.socj_currentx ="X" and l.department != pm_dept AND l.department between 60 and 69 and pm_dept between 60 and 99
and IF(l.department = 62 && p.pm_dept = 68,1,0)=0 and IF(l.department = 68 && p.pm_dept = 62,1,0)=0

order by AdjDept,Direction DESC,InFromOutTO, job DESC;
END $$

DELIMITER ;