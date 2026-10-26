# Write your MySQL query statement below
SELECT *
FROM Cinema AS C
WHERE C.id%2!=0 && C.description!='boring'
ORDER BY C.rating DESC