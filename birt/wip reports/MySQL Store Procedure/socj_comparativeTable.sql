DROP TABLE IF EXISTS `pqs`.`socj_comparatives`;
CREATE TABLE  `pqs`.`socj_comparatives` (
  `pm_dept` int(10) unsigned NOT NULL,
  `pm_name` varchar(45) NOT NULL,
  `pm_clk` varchar(45) NOT NULL,
  `act_booking` double DEFAULT NULL,
  `act_backlog` double DEFAULT NULL,
  `act_revenue` double DEFAULT NULL,
  `act_profit` double DEFAULT NULL,
  `act_mu` double DEFAULT NULL,
  `pre_booking` double DEFAULT NULL,
  `pre_backlog` double DEFAULT NULL,
  `pre_revenue` double DEFAULT NULL,
  `pre_profit` double DEFAULT NULL,
  `pre_mu` double DEFAULT NULL,
  `budget_booking` double DEFAULT NULL,
  `budget_revenue` double DEFAULT NULL,
  `budget_profit` double DEFAULT NULL,
  `budget_mu` double DEFAULT NULL,
  PRIMARY KEY (`pm_clk`,`pm_name`,`pm_dept`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;