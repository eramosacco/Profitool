SELECT  j.Content as job, ac.Content as activity, p.Content as project, 
sum(t.TimeTaken) as TimeTaken, group_concat(distinct((concat(t.ObjectId,':',k.Subject,IF(k.Subject not like '%By:%',concat(' by ', IFNULL(r.Requestor,u.Name)),''))))) as memo, 
DATE_FORMAT(CONVERT_TZ(t.created,'+00:00','SYSTEM'),'%Y/%m/%d') as created
FROM Transactions t
JOIN Attachments a ON t.id = a.TransactionId
JOIN Users u ON t.creator = u.id
JOIN Tickets k ON t.ObjectId = k.id
LEFT JOIN ObjectCustomFieldValues j on j.ObjectId = t.ObjectId AND j.CustomField=1 AND j.Disabled =0
LEFT JOIN ObjectCustomFieldValues ac on ac.ObjectId = t.ObjectId AND ac.CustomField=3 AND ac.Disabled =0
LEFT JOIN ObjectCustomFieldValues p on p.ObjectId = t.ObjectId AND p.CustomField=2 AND p.Disabled =0
LEFT JOIN Requestor r on t.ObjectId = r.TicketId
WHERE u.name= 'dgirard' and a.parent = 0
AND CONVERT_TZ(t.created,'+00:00','SYSTEM') BETWEEN '2013-03-25' AND '2013-03-30'
AND t.TimeTaken > 0
GROUP BY job,project,activity,created ORDER BY created