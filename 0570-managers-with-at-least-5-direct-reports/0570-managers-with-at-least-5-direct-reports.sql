# Write your MySQL query statement below
SELECT S1.name
FROM Employee AS S1
JOIN Employee AS S2
ON S1.id=S2.managerId
GROUP BY S1.id,S1.name
HAVING COUNT(S2.id)>=5;