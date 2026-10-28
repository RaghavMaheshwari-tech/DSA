# Write your MySQL query statement below
SELECT R.contest_id, ROUND((COUNT(R.contest_id)*100/(SELECT COUNT(user_id) FROM Users)),2) AS percentage
FROM Users AS U
RIGHT JOIN Register AS R
ON U.user_id=R.user_id
GROUP BY R.contest_id
ORDER BY percentage DESC , R.contest_id ASC