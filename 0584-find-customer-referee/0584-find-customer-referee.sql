# Write your MySQL query statement below
-- SELECT name FROM Customer
-- WHERE referee_id NOT IN('2'); #ismai null wale bhi ht jayenge 

SELECT name FROM Customer
WHERE referee_id != 2 OR referee_id IS NULL