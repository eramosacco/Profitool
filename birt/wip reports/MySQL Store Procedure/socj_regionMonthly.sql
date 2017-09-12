DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_RegionMonthly` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_RegionMonthly`(IN YearEnd VARCHAR(50),IN company VARCHAR(4))
BEGIN
  DECLARE done INT DEFAULT FALSE;
  DECLARE a CHAR(16);
  DECLARE x  INT;
  DECLARE prevMonth CHAR(16);
  DECLARE mth INT;
  DECLARE col  VARCHAR(255);
  DECLARE cur1 CURSOR FOR SELECT distinct(socj_date_effective) from soc_journal where socj_date_effective > YearEnd order by socj_date_effective ;
  #DECLARE cur2 CURSOR FOR SELECT i FROM test.t2;
  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

      SET x = 0;
      SET mth = 10;
      SET prevMonth = YearEnd;
  OPEN cur1;
  #OPEN cur2;
  DELETE from socj_regionMonthly;
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
    SET @s = Concat('Insert into socj_regionMonthly (coid,Department, DepartmentName,DepartmentDivision,DepartmentGroup,',col,')
select "',company,'", p.pm_dept as Department , UPPER(r.department_name) as DepartmentName,
UPPER(r.rollup_division) as DepartmentDivision, UPPER(r.rollup_group) as DepartmentGroup,
 (sum(p.pm_pct*IFNULL(j.socj_revest_total,0)/100)- sum(p.pm_pct*IFNULL(s.socj_revest_total,0)/100)) as booking
from soc_journal j
LEFT join (select * from soc_journal where socj_date_effective = "',prevMonth,'" and binary socj_coid = binary "',company,'" and socj_currentx = "X") s
ON j.socj_job = s.socj_job and j.socj_phase = s.socj_phase

JOIN soc_pm_info_log p ON p.job = j.socj_job and p.phase = j.socj_phase
and j.socj_coid = p.coid  and j.socj_date_effective = p.report_Date
and j.socj_run_time = p.run_time


JOIN dept_rollup r
ON (IF(p.pm_dept=42,62,pm_dept) = r.department_number
OR IF(p.pm_dept=41,61,pm_dept) = r.department_number)
and j.socj_coid = r. coid

where j.socj_date_effective = "',a,'" and binary j.socj_coid = binary "',company,'" and j.socj_currentx = "X"

group by CASE WHEN p.pm_dept =42 then 62
              WHEN p.pm_dept =41 then 61
          ELSE p.pm_dept
        END

order by r.rollup_division, p.pm_dept
ON DUPLICATE KEY UPDATE ',col,' = VALUES(',col,')');
          Prepare stmt1 from @s;
          Execute stmt1;# using @a, @b;

          DEALLOCATE PREPARE stmt1;
  set x = x+1;
  set mth = 10;
  set prevMonth = a;
  END LOOP;

  CLOSE cur1;
  SELECT * from socj_regionMonthly;
END $$

DELIMITER ;