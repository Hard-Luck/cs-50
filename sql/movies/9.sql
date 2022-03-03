SELECT name from people WHERE id in
(SELECT DISTINCT person_id from stars where movie_id IN
(SELECT id FROM movies WHERE year = 2004))
ORDER BY birth;
