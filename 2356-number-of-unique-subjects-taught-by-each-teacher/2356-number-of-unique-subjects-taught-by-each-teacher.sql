# Write your MySQL query statement below
SELECT M.teacher_id,COUNT(M.teacher_id) AS cnt
FROM (SELECT T.teacher_id,T.subject_id
FROM Teacher T
GROUP BY teacher_id,subject_id) M
GROUP BY M.teacher_id
