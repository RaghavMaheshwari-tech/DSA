# Write your MySQL query statement below
-- SELECT A1.machine_id, A1.timestamp, A2.timestamp
-- FROM Activity A1
-- JOIN Activity A2
-- ON A1.machine_id=A2.machine_id
-- AND A1.process_id=A2.process_id
-- AND A1.timestamp<A2.timestamp

-- | machine_id | timestamp | timestamp |
-- | ---------- | --------- | --------- |
-- | 0          | 0.712     | 1.52      |
-- | 0          | 3.14      | 4.12      |
-- | 1          | 0.55      | 1.55      |
-- | 1          | 0.43      | 1.42      |
-- | 2          | 4.1       | 4.512     |
-- | 2          | 2.5       | 5         |

-- SELECT A1.machine_id, ROUND(AVG(A2.timestamp-A1.timestamp),3) AS processing_time
-- FROM Activity A1
-- JOIN Activity A2
-- ON A1.machine_id=A2.machine_id
-- AND A1.process_id=A2.process_id
-- AND A1.timestamp<A2.timestamp ..... ISNE EQUAL WALA NHI LIYA 
-- GROUP BY A1.machine_id

-- | machine_id | process_id | activity_type | timestamp |
-- | ---------- | ---------- | ------------- | --------- |
-- | 0          | 0          | start         | 0.712     |
-- | 0          | 0          | end           | 1.52      |
-- | 0          | 1          | start         | 3.14      |
-- | 0          | 1          | end           | 4.12      |
-- | 0          | 2          | start         | 4.14      |
-- | 0          | 2          | end           | 4.14      |
-- View more

-- Use Testcase
-- Output
-- | machine_id | processing_time |
-- | ---------- | --------------- |
-- | 0          | 0.894           |
-- | 1          | 0.995           |
-- | 2          | 1.456           |
-- Expected
-- | machine_id | processing_time |
-- | ---------- | --------------- |
-- | 0          | 0.596           |
-- | 1          | 0.995           |
-- | 2          | 1.456           |

SELECT A1.machine_id, ROUND(AVG(A2.timestamp-A1.timestamp),3) AS processing_time
FROM Activity A1
JOIN Activity A2
ON A1.machine_id=A2.machine_id
AND A1.process_id=A2.process_id
AND A1.activity_type = 'start'
AND A2.activity_type = 'end'
GROUP BY A1.machine_id
