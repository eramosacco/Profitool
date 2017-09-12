DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_pmMonthlyACCO` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_pmMonthlyACCO`(IN YearEnd VARCHAR(50))
BEGIN
  DECLARE done INT DEFAULT FALSE;
  DECLARE a CHAR(16);
  DECLARE x  INT;
  DECLARE mth INT;
  DECLARE col  VARCHAR(255);
  DECLARE cur1 CURSOR FOR SELECT distinct(socj_date_effective) from soc_journal where socj_date_effective > YearEnd;
  #DECLARE cur2 CURSOR FOR SELECT i FROM test.t2;
  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

      SET x = 0;
      SET mth = 10;
  OPEN cur1;
  #OPEN cur2;
  Delete from pqs.socj_pmMonthlyACCO;

  read_loop: LOOP
    FETCH cur1 INTO a;
    IF done THEN
      LEAVE read_loop;
    END IF;
    SET mth = mth + x;
    IF mth > 12 THEN
       SET mth = mth -12;
    END IF;
    SET col = concat("Booking",mth);
    SET @s = Concat('Insert into socj_pmMonthlyACCO (Department, pm_clk,pm_name, pm_dpt,job, phase,',col,')
select (e.department+0) as Department ,p.pm_clk, p.pm_name, p.pm_dept, (j.socj_job+0) as job, (j.socj_phase) as phase,
 pm_pct*(sum(j.socj_revest_total)- sum(s.socj_revest_total))/100 as booking
from soc_journal j
LEFT join (select * from soc_journal where socj_date_effective = ',YearEnd,') s
ON j.socj_job = s.socj_job and j.socj_phase = s.socj_phase
JOIN soc_extension e
ON j.socj_job = e.job and j.socj_phase = e.phase
and j.socj_date_effective = e.report_Date
and j.socj_coid = e.coid
JOIN socj_pm p ON p.job = j.socj_job and p.phase = j.socj_phase and j.socj_coid = p.coid
where j.socj_date_effective = ',a,' and j.socj_coid = "ACCO"
group by p.pm_clk
ON DUPLICATE KEY UPDATE ',col,' = VALUES(',col,')');
          Prepare stmt1 from @s;
          Execute stmt1;# using @a, @b;

          DEALLOCATE PREPARE stmt1;
  set x = x +1;
  END LOOP;

  CLOSE cur1;
  SELECT * from pqs.socj_pmMonthlyACCO;
END $$

DELIMITER ;