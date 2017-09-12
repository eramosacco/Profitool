DROP TABLE IF EXISTS `pqs`.`socj_pmMonthly`;
CREATE TABLE  `pqs`.`socj_pmMonthly` (
  `coid` varchar(45) NOT NULL,
  `Department` int(10) unsigned NOT NULL,
  `pm_clk` int(10) unsigned NOT NULL,
  `pm_name` varchar(45) NOT NULL,
  `pm_dpt` int(10) unsigned NOT NULL,
  `job` int(10) unsigned NOT NULL,
  `phase` int(10) unsigned NOT NULL,
  `Booking10` double NOT NULL,
  `Booking11` double NOT NULL,
  `Booking12` double NOT NULL,
  `Booking1` double NOT NULL,
  `Booking2` double NOT NULL,
  `Booking3` double NOT NULL,
  `Booking4` double NOT NULL,
  `Booking5` double NOT NULL,
  `Booking6` double NOT NULL,
  `Booking7` double NOT NULL,
  `Booking8` double NOT NULL,
  `Booking9` double NOT NULL,
  PRIMARY KEY  (`pm_clk`,`coid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;