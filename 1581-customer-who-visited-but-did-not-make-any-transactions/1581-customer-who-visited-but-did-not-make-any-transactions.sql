# Write your MySQL query statement below
SELECT customer_id,count(customer_id) AS count_no_trans
FROM Visits 
LEFT JOIN Transactions
ON Visits.visit_id=Transactions.visit_id
WHERE transaction_id IS NULL
GROUP BY customer_id; # IT IS USED WHENEVER U USED AGGREGATE FUNCTION