# Write your MySQL query statement below
SELECT P.product_id, IFNULL(ROUND(SUM(P.price*U.units)/SUM(U.units),2),0.00) AS average_price
FROM Prices AS P
LEFT JOIN UnitsSold AS U
ON U.product_id=P.product_id && U.purchase_date>=P.start_date && U.purchase_date<=P.end_date
GROUP BY P.product_id

