# Write your MySQL query statement below
SELECT name,bonus
FROM Employee
LEFT JOIN Bonus
ON Employee.empId=Bonus.empId
WHERE Bonus.bonus<1000 || Bonus.bonus IS NULL;