SELECT name from people where id in
(
SELECT person_id from stars where movie_id IN
(SELECT id FROM movies WHERE title LIKE "toy story"));
