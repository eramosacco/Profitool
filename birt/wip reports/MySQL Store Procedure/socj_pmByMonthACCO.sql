DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_pmByMonthACCO` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_pmByMonthACCO`(IN preYearEnd VARCHAR(50), IN monthEnd VARCHAR(50))
BEGIN
select (e.department+0) as Department ,p.pm_clk, p.pm_name, p.pm_dept, (j.socj_job+0) as job,
 pm_pct*(sum(j.socj_revest_total)- sum(s.socj_revest_total))/100 as booking
from soc_journal j
LEFT join (select * from soc_journal where socj_date_effective = preYearEnd) s
ON j.socj_job = s.socj_job and j.socj_phase = s.socj_phase
JOIN soc_extension e
ON j.socj_job = e.job and j.socj_phase = e.phase
and j.socj_date_effective = e.report_Date
and j.socj_coid = e.coid
JOIN socj_pm p ON p.job = j.socj_job and p.phase = j.socj_phase and j.socj_coid = p.coid
where j.socj_date_effective = monthEnd and j.socj_coid = "ACCO"
group by p.pm_clk;

END $$

DELIMITER ;