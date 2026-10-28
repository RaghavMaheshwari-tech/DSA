# Write your MySQL query statement below
SELECT 
    Q.query_name,  
    ROUND((SUM(Q.rating/Q.position))/COUNT(Q.query_name),2) AS quality,
    ROUND(AVG((Q.rating<3)*100),2) AS poor_query_percentage
FROM Queries AS Q
GROUP BY Q.query_name
