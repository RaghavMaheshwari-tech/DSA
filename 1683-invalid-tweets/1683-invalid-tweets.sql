# Write your MySQL query statement below
SELECT tweet_id from Tweets 
WHERE CHAR_LENGTH(content)>15; # it is used to find the length of the line