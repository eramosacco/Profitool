DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_comparativeACCO` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_comparativeACCO`(IN currYearEnd VARCHAR(50), IN currMonthEnd VARCHAR(50), IN preYearEnd VARCHAR(50), IN preMonthEnd VARCHAR(50))
BEGIN

DELETE from socj_comparatives;

#populate current actual number
INSERT INTO socj_comparatives (pm_dept,pm_name,pm_clk,act_booking,act_backlog,act_revenue, act_profit,act_mu)
select #p.department as CostDept,
pm_dept as pm_dept, pm_name, pm_clk,
Sum((IFNULL(j.socj_RevEst_Total,0) - IFNULL(s.socj_RevEst_Total,0)) * pm_pct/100) as Bookings,

sum((IFNULL(j.socj_revest_Total,0) - ((IFNULL(j.socj_RevAct_Billings,0) + IFNULL(j.socj_Earn_exceed_bill,0)) -IFNULL(j.socj_Bill_exceed_earn,0))) * pm_pct/100) as Backlog,
sum(((IFNULL(j.socj_GP_curr_yr,0) + IFNULL(j.socj_GP_prior_yr,0) +IFNULL(j.socj_CostAct,0)) - ((IFNULL(s.socj_GP_curr_yr,0) + IFNULL(s.socj_GP_prior_yr,0) +IFNULL(s.socj_CostAct,0)))) * pm_pct/100) as Revenue,

sum(j.socj_GP_curr_yr * pm_pct/100) as Profit,
(sum(j.socj_GP_curr_yr * pm_pct/100) / ((sum(((IFNULL(j.socj_GP_curr_yr,0) + IFNULL(j.socj_GP_prior_yr,0) +IFNULL(j.socj_CostAct,0)) - ((IFNULL(s.socj_GP_curr_yr,0) + IFNULL(s.socj_GP_prior_yr,0) +IFNULL(s.socj_CostAct,0)))) * pm_pct/100))-
(sum(j.socj_GP_curr_yr * pm_pct/100))))*100

#(sum(j.socj_GP_curr_yr * pm_pct/100) /((
#(sum(IFNULL(j.socj_GP_curr_yr,0) + IFNULL(j.socj_GP_prior_yr,0) +IFNULL(j.socj_CostAct,0)) - ((IFNULL(s.socj_GP_curr_yr,0) + IFNULL(s.socj_GP_prior_yr,0) +IFNULL(s.socj_CostAct,0)))) * pm_pct/100)) -
#sum(j.socj_GP_curr_yr * pm_pct/100)))

From soc_journal j

INNER JOIN socj_pm p
ON j.socj_job = p.job
AND j.socj_phase = p.phase
and j.socj_coid = p.coid
and j.socj_Date_effective = p.report_date

LEFT JOIN ( select * from soc_journal where socj_Date_effective = currYearEnd and socj_currentx ="X") s
ON j.socj_job = s.socj_job  and j.socj_phase = s.socj_phase AND j.socj_coid = s.socj_coid

WHERE j.socj_Date_effective = currMonthEnd and j.socj_coid = "ACCO" and p.report_date = currMonthEnd and
j.socj_currentx ="X"
group by pm_clk
order by pm_dept;

#populate previous period number

INSERT INTO socj_comparatives (pm_dept,pm_name,pm_clk,pre_booking,pre_backlog,pre_revenue, pre_profit,pre_mu)
select #p.department as CostDept,
pm_dept as pm_dept, pm_name, pm_clk,
Sum((IFNULL(j.socj_RevEst_Total,0) - IFNULL(s.socj_RevEst_Total,0)) * pm_pct/100) as Bookings,

sum((IFNULL(j.socj_revest_Total,0) - ((IFNULL(j.socj_RevAct_Billings,0) + IFNULL(j.socj_Earn_exceed_bill,0)) -IFNULL(j.socj_Bill_exceed_earn,0))) * pm_pct/100) as Backlog,
sum(((IFNULL(j.socj_GP_curr_yr,0) + IFNULL(j.socj_GP_prior_yr,0) +IFNULL(j.socj_CostAct,0)) - ((IFNULL(s.socj_GP_curr_yr,0) + IFNULL(s.socj_GP_prior_yr,0) +IFNULL(s.socj_CostAct,0)))) * pm_pct/100) as Revenue,

sum(j.socj_GP_curr_yr * pm_pct/100) as Profit,
(sum(j.socj_GP_curr_yr * pm_pct/100) / ((sum(((IFNULL(j.socj_GP_curr_yr,0) + IFNULL(j.socj_GP_prior_yr,0) +IFNULL(j.socj_CostAct,0)) - ((IFNULL(s.socj_GP_curr_yr,0) + IFNULL(s.socj_GP_prior_yr,0) +IFNULL(s.socj_CostAct,0)))) * pm_pct/100))-
(sum(j.socj_GP_curr_yr * pm_pct/100))))*100

#(sum(j.socj_GP_curr_yr * pm_pct/100) /((
#(sum(IFNULL(j.socj_GP_curr_yr,0) + IFNULL(j.socj_GP_prior_yr,0) +IFNULL(j.socj_CostAct,0)) - ((IFNULL(s.socj_GP_curr_yr,0) + IFNULL(s.socj_GP_prior_yr,0) +IFNULL(s.socj_CostAct,0)))) * pm_pct/100)) -
#sum(j.socj_GP_curr_yr * pm_pct/100)))

From soc_journal j

INNER JOIN socj_pm p
ON j.socj_job = p.job
AND j.socj_phase = p.phase
and j.socj_coid = p.coid
and j.socj_Date_effective = p.report_date

LEFT JOIN ( select * from soc_journal where socj_Date_effective = preYearEnd and socj_currentx ="X") s
ON j.socj_job = s.socj_job  and j.socj_phase = s.socj_phase AND j.socj_coid = s.socj_coid

WHERE j.socj_Date_effective = preMonthEnd and j.socj_coid = "ACCO" and p.report_date = preMonthEnd and
j.socj_currentx ="X"
group by pm_clk
order by pm_dept
ON DUPLICATE KEY UPDATE  pre_booking = values(pre_booking), pre_backlog = values(pre_backlog) , pre_revenue = values(pre_revenue), pre_profit = values(pre_profit), pre_mu = values(pre_mu);

select * from socj_comparatives order by pm_dept;
END $$

DELIMITER ;