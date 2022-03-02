SELECT DISTINCT person_id from stars where movie_id in(
SELECT movie_id FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
where name LIKE "Kevin Bacon" and birth = 1958);


