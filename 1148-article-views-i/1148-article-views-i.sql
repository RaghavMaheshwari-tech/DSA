# Write your MySQL query statement below
SELECT DISTINCT author_id AS id FROM Views
WHERE author_id=viewer_id # hm yha id==viewer_id nhi likh skte kyonki as lgane ke bad woh kew output table mai show hota hai actual table mai author_id hi hai , yeh koi reference nhi hota..
ORDER BY id ASC;