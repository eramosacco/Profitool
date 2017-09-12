DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_DepartmentalAdj3` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_DepartmentalAdj3`(IN fromDate VARCHAR(50), IN toDate VARCHAR(50),IN company VARCHAR(50))
BEGIN
select Department,
d.department_name,
d.rollup_division,
d.rollup_group,
# sum(if(Direction="<--",Bookings,0)) ,sum(if(Direction="-->",Bookings,0)),
sum(if(Direction="<--",Bookings,0)) - sum(if(Direction="-->",Bookings,0)) as Bookings,
sum(if(Direction="<--",Backlog,0)) - sum(if(Direction="-->",Backlog,0)) as Backlog,
sum(if(Direction="<--",Revenue,0)) - sum(if(Direction="-->",Revenue,0)) as Revenue,
sum(if(Direction="<--",Profit,0)) - sum(if(Direction="-->",Profit,0)) as Profit




from (
select j.socj_coid as coid,(l.department+0) as Department,"-->" as Direction,pm_dept as InFromOutTo, (j.socj_job +0) as job, (j.socj_phase+0) as phase, UPPER(l.name) as JobName,
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
and j.socj_run_time = l.run_time

INNER JOIN soc_pm_info_log p
ON j.socj_job = p.job
AND j.socj_phase = p.phase
and j.socj_coid = p.coid
and j.socj_date_effective = p.report_date
and j.socj_run_time = p.run_time



LEFT JOIN ( select * from soc_journal where socj_Date_effective = fromDate and socj_currentx ="X") s
ON j.socj_job = s.socj_job AND j.socj_coid = s.socj_coid

WHERE j.socj_Date_effective = toDate and  binary j.socj_coid = binary company and p.report_date = toDate and
j.socj_currentx ="X" and l.department != pm_dept AND l.department between 60 and 69 and pm_dept between 60 and 99
and IF(l.department = 62 && p.pm_dept = 68,1,0)=0 and IF(l.department = 68 && p.pm_dept = 62,1,0)=0

UNION

select  j.socj_coid as coid, pm_dept as Department, "<--" as Direction , (l.department+0) as InFromOutTo,(j.socj_job +0) as job, (j.socj_phase+0) as phase, UPPER(l.name) as JobName,
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
and j.socj_run_time = l.run_time


INNER JOIN soc_pm_info_log p
ON j.socj_job = p.job
AND j.socj_phase = p.phase
and j.socj_coid = p.coid
and j.socj_date_effective = p.report_date
and j.socj_run_time = p.run_time



LEFT JOIN ( select * from soc_journal where socj_Date_effective = fromDate and socj_currentx ="X") s
ON j.socj_job = s.socj_job AND j.socj_coid = s.socj_coid

WHERE j.socj_Date_effective = toDate and binary j.socj_coid = binary company and p.report_date = toDate and
j.socj_currentx ="X" and l.department != pm_dept AND l.department between 60 and 69 and pm_dept between 60 and 99
and IF(l.department = 62 && p.pm_dept = 68,1,0)=0 and IF(l.department = 68 && p.pm_dept = 62,1,0)=0



UNION
select j.socj_coid as coid,(l.department+0) as Department,"-->" as Direction,pm_dept as InFromOutTo, (j.socj_job +0) as job, (j.socj_phase+0) as phase, UPPER(l.name) as JobName,
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
and j.socj_run_time = l.run_time

INNER JOIN soc_pm_info_log p
ON j.socj_job = p.job
AND j.socj_phase = p.phase
and j.socj_coid = p.coid
and j.socj_date_effective = p.report_date
and j.socj_run_time = p.run_time



LEFT JOIN ( select * from soc_journal where socj_Date_effective = fromDate and socj_currentx ="X") s
ON j.socj_job = s.socj_job AND j.socj_coid = s.socj_coid

WHERE j.socj_Date_effective = toDate and  binary j.socj_coid = binary company and p.report_date = toDate and
j.socj_currentx ="X" and l.department != pm_dept AND l.department between 71 and 99 and pm_dept between 60 and 69

order by Department,Direction DESC,InFromOutTO, job DESC

) as a
JOIN dept_rollup d
on d.department_number = a.Department
and d.coid = a.coid
group by  Department;
END $$

DELIMITER ;