DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_regionByMonthACCO` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_regionByMonthACCO`(IN preYearEnd VARCHAR(50), IN monthEnd VARCHAR(50))
BEGIN
select (e.department+0) as Department , UPPER(r.department_name) as DepartmentName,
UPPER(r.rollup_division) as DepartmentDivision, UPPER(r.rollup_group) as DepartmentGroup,
 sum(j.socj_revest_total)- sum(s.socj_revest_total) as booking
from soc_journal j
LEFT join (select * from soc_journal where socj_date_effective = preYearEnd) s
ON j.socj_job = s.socj_job and j.socj_phase = s.socj_phase
JOIN soc_extension e
ON j.socj_job = e.job and j.socj_phase = e.phase
and j.socj_date_effective = e.report_Date
and j.socj_coid = e.coid
JOIN dept_rollup r
ON e.department = r.department_number
where j.socj_date_effective = monthEnd and j.socj_coid = "ACCO"
group by e.department;

END $$

DELIMITER ;