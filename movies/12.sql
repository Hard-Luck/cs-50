SELECT * from(
SELECT * from movies
WHERE id IN
(SELECT movie_id from stars where person_id = 136))
Where ;

-- and person_id = 307)