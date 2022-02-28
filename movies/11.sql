SELECT movies.title, ratings.rating
FROM movies
INNER JOIN ratings ON movies.id = ratings.movie_id
WHERE id IN(
SELECT movie_id from ratings where movie_id IN(
SELECT movie_id from stars where person_id IN(
SELECT id from people WHERE name LIKE "Chadwick Boseman")))
ORDER BY rating DESC
LIMIT 5;