# Write your MySQL query statement below
SELECT 
    DATE_FORMAT(T.trans_date, '%Y-%m') AS month,
    T.country,
    COUNT(T.state) AS trans_count,
    SUM(T.state='approved') AS approved_count,
    SUM(T.amount) AS trans_total_amount,
    SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount
FROM Transactions AS T
GROUP BY T.country,month
