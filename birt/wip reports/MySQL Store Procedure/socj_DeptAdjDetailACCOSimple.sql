DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_DeptAdjDetailSimpleACCO` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_DeptAdjDetailSimpleACCO`(IN fromDate VARCHAR(50), IN toDate VARCHAR(50))
BEGIN
select (p.department+0) as AdjDept,"-->" as Direction,pm_dept as InFromOutTo, (j.socj_job +0) as job, (j.socj_phase+0) as phase, UPPER(p.job_name) as JobName,
(p.department+0) as CostDept, pm_clk, pm_name, pm_pct, pm_dept as pm_dept,
(IFNULL(j.socj_RevEst_Total,0) - IFNULL(s.socj_RevEst_Total,0)) * pm_pct/100 as Bookings,

(IFNULL(j.socj_revest_Total,0) - ((IFNULL(j.socj_RevAct_Billings,0) + IFNULL(j.socj_Earn_exceed_bill,0)) -IFNULL(j.socj_Bill_exceed_earn,0))) * pm_pct/100 as Backlog,
((IFNULL(j.socj_GP_curr_yr,0) + IFNULL(j.socj_GP_prior_yr,0) +IFNULL(j.socj_CostAct,0)) - ((IFNULL(s.socj_GP_curr_yr,0) + IFNULL(s.socj_GP_prior_yr,0) +IFNULL(s.socj_CostAct,0)))) * pm_pct/100 as Revenue,
j.socj_GP_curr_yr * pm_pct/100 as Profit
From soc_journal j

INNER JOIN socj_pm p
ON j.socj_job = p.job
AND j.socj_phase = p.phase
and j.socj_coid = p.coid

LEFT JOIN ( select * from soc_journal where socj_Date_effective = fromDate and socj_currentx ="X") s
ON j.socj_job = s.socj_job AND j.socj_coid = s.socj_coid

WHERE j.socj_Date_effective = toDate and j.socj_coid = "ACCO" and p.report_date = toDate and
j.socj_currentx ="X" and p.department != pm_dept AND ((p.department between 60 and 69) OR (pm_dept between 60 and 69))


UNION

select  pm_dept as AdjDept, "<--" as Direction , (p.department+0) as InFromOutTo,(j.socj_job +0) as job, (j.socj_phase+0) as phase, UPPER(p.job_name) as JobName,
(p.department+0) as CostDept, pm_clk, pm_name, pm_pct, pm_dept as pm_dept,
(IFNULL(j.socj_RevEst_Total,0) - IFNULL(s.socj_RevEst_Total,0)) * pm_pct/100 as Bookings,

(IFNULL(j.socj_revest_Total,0) - ((IFNULL(j.socj_RevAct_Billings,0) + IFNULL(j.socj_Earn_exceed_bill,0)) -IFNULL(j.socj_Bill_exceed_earn,0))) * pm_pct/100 as Backlog,
((IFNULL(j.socj_GP_curr_yr,0) + IFNULL(j.socj_GP_prior_yr,0) +IFNULL(j.socj_CostAct,0)) - ((IFNULL(s.socj_GP_curr_yr,0) + IFNULL(s.socj_GP_prior_yr,0) +IFNULL(s.socj_CostAct,0)))) * pm_pct/100 as Revenue,
j.socj_GP_curr_yr * pm_pct/100 as Profit
From soc_journal j

INNER JOIN socj_pm p
ON j.socj_job = p.job
AND j.socj_phase = p.phase
and j.socj_coid = p.coid

LEFT JOIN ( select * from soc_journal where socj_Date_effective = fromDate and socj_currentx ="X") s
ON j.socj_job = s.socj_job AND j.socj_coid = s.socj_coid

WHERE j.socj_Date_effective = toDate and j.socj_coid = "ACCO" and p.report_date = toDate and
j.socj_currentx ="X" and p.department != pm_dept AND ((p.department between 60 and 69) OR (pm_dept between 60 and 69))

order by AdjDept,Direction DESC,InFromOutTO;
END $$

DELIMITER ;