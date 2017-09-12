DROP TABLE IF EXISTS `pqs`.`socj_regionMonthly`;
CREATE TABLE  `pqs`.`socj_regionMonthly` (
  `Department` int(10) unsigned NOT NULL auto_increment,
  `DepartmentName` varchar(45) NOT NULL,
  `DepartmentDivision` varchar(45) NOT NULL,
  `DepartmentGroup` varchar(45) NOT NULL,
  `Booking10` double default NULL,
  `Booking11` double default NULL,
  `Booking12` double default NULL,
  `Booking1` double default NULL,
  `Booking2` double default NULL,
  `Booking3` double default NULL,
  `Booking4` double default NULL,
  `Booking5` double default NULL,
  `Booking6` double default NULL,
  `Booking7` double default NULL,
  `Booking8` double default NULL,
  `Booking9` double default NULL,
  `coid` varchar(45) NOT NULL,
  PRIMARY KEY  USING BTREE (`Department`,`coid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;