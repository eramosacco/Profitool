DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_pmMonthly` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_pmMonthly`(IN YearEnd VARCHAR(50), IN company VARCHAR(50))
BEGIN
  DECLARE done INT DEFAULT FALSE;
  DECLARE a CHAR(16);
  DECLARE prevMonth CHAR(16);
  DECLARE x  INT;
  DECLARE mth INT;
  DECLARE col  VARCHAR(255);
  DECLARE cur1 CURSOR FOR SELECT distinct(socj_date_effective) from soc_journal where socj_date_effective > YearEnd order by 1;
  #DECLARE cur2 CURSOR FOR SELECT i FROM test.t2;
  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

      SET x = 0;
      SET mth = 10;
      SET prevMonth = YearEnd;
  OPEN cur1;
  #OPEN cur2;
  Delete from pqs.socj_pmMonthly;

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
    SET @s = Concat('Insert into socj_pmMonthly (coid,Department, pm_clk,pm_name, pm_dpt,job, phase,',col,')
select "',company,'", (p.pm_dept+0) as Department ,p.pm_clk, p.pm_name, p.pm_dept, (j.socj_job+0) as job, (j.socj_phase) as phase,
(sum(IFNULL(j.socj_revest_total,0)*pm_pct/100)- sum(IFNULL(s.socj_revest_total,0)*pm_pct/100)) as booking
FROM soc_journal j

LEFT join (select * from soc_journal where socj_date_effective = "',prevMonth,'" and binary socj_coid  = binary "',company,'" and socj_currentx="X") s
ON j.socj_job = s.socj_job and j.socj_phase = s.socj_phase
and j.socj_coid = s.socj_coid

JOIN soc_pm_info_log p ON p.job = j.socj_job and p.phase = j.socj_phase and j.socj_coid = p.coid
and j.socj_date_effective = p.report_date and j.socj_run_time = p.run_time
where j.socj_date_effective = "',a,'" and binary j.socj_coid = binary"',company,'" and j.socj_currentx="X"
group by p.pm_clk
order by pm_dept
ON DUPLICATE KEY UPDATE ',col,' = VALUES(',col,')');
          Prepare stmt1 from @s;
          Execute stmt1;# using @a, @b;

          DEALLOCATE PREPARE stmt1;

  set x = x +1;
  set mth = 10;
  set prevMonth = a;
  END LOOP;

  CLOSE cur1;
  SELECT * from pqs.socj_pmMonthly where binary coid = binary company order by Department,pm_name;
END $$

DELIMITER ;