# Write your MySQL query statement below
-- SELECT teacher_id,COUNT(teacher_id) AS cnt
-- FROM Teacher
-- WHERE(teacher_id,subject_id) IN (
    
-- )
-- GROUP BY teacher_id
SELECT M.teacher_id,COUNT(M.teacher_id) AS cnt
FROM (SELECT T.teacher_id,T.subject_id
FROM Teacher T
GROUP BY teacher_id,subject_id) M
GROUP BY M.teacher_id
