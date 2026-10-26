# Write your MySQL query statement below
SELECT S1.user_id, IFNULL(ROUND(SUM(c1.action='confirmed')/COUNT(*),2),0.00) AS confirmation_rate
FROM Signups AS s1
LEFT JOIN Confirmations AS c1
ON s1.user_id=c1.user_id
GROUP BY S1.user_id 