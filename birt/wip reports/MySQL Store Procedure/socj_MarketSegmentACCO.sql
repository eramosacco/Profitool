DELIMITER $$

DROP PROCEDURE IF EXISTS `socj_MarketSegmentACCO` $$
CREATE DEFINER=`bvu`@`10.100.4.13` PROCEDURE `socj_MarketSegmentACCO`(IN fromDate VARCHAR(50), IN toDate VARCHAR(50))
BEGIN
select UPPER(e.market_segment_desc) as MarketSegment ,UPPER(e.branch_name) as BranchName,
#Booking
sum(IFNULL(j.socj_RevEst_total,0)) as bookingThisYear,
sum(IFNULL(p.socj_RevEst_total,0)) as bookingLastYear,
sum(IFNULL(j.socj_RevEst_total,0)) - sum(IFNULL(p.socj_RevEst_total,0)) as Bookings,

#Backlogs
sum(j.socj_RevEst_Total) - ((sum(j.socj_RevAct_billings) + sum(j.socj_Earn_exceed_bill)) -sum(j.socj_Bill_exceed_earn)) as Backlog,

#Revenue
sum((IFNULL(j.socj_RevAct_billings,0) + IFNULL(j.socj_Earn_exceed_bill,0)) - IFNULL(j.socj_Bill_exceed_earn,0)) as revenueThisYear,
sum((IFNULL(p.socj_RevAct_billings,0) + IFNULL(p.socj_Earn_exceed_bill,0)) -IFNULL(p.socj_Bill_exceed_earn,0)) as revenueLastYear,

sum((IFNULL(j.socj_RevAct_billings,0) + IFNULL(j.socj_Earn_exceed_bill,0)) - IFNULL(j.socj_Bill_exceed_earn,0))-
sum((IFNULL(p.socj_RevAct_billings,0) + IFNULL(p.socj_Earn_exceed_bill,0)) -IFNULL(p.socj_Bill_exceed_earn,0)) as Revenue,

#Profit
sum((IFNULL(j.socj_RevAct_billings,0) + IFNULL(j.socj_Earn_exceed_bill,0)) - IFNULL(j.socj_Bill_exceed_earn,0))-
sum((IFNULL(p.socj_RevAct_billings,0) + IFNULL(p.socj_Earn_exceed_bill,0)) -IFNULL(p.socj_Bill_exceed_earn,0)) -
(sum(IFNULL(j.socj_CostAct,0))-sum(IFNULL(p.socj_CostAct,0))) as Profit

From soc_journal j
#Join with last year data, use left join to include job that was not in last year but new for this year.
LEFT JOIN ( select * from soc_journal where socj_Date_effective = fromDate and socj_currentx ="X") p
ON j.socj_job = p.socj_job AND j.socj_coid = p.socj_coid
#Join with extension for extra info
JOIN soc_extension e
ON j.socj_job = e.job and
   j.socj_phase = e.phase and
   j.socj_Date_effective = e.report_date and
   j.socj_coid = e.coid
# where clause to include currentx = X (This may be an issue)
where #j.socj_job = 611227 and
j.socj_currentx = "X" and
j.socj_Date_effective = toDate AND j.socj_coid ="ACCO"
group by e.market_segment_desc ,e.branch_name#, j.socj_coid# v, socj_job
order by e.market_segment_desc ,e.branch_name;
END $$

DELIMITER ;