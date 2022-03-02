SELECT DISTINCT name from people
JOIN stars ON people.id = stars.person_id
WHERE movie_id in(
SELECT movie_id FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
where name LIKE "Kevin Bacon" and birth = 1958)
ORDER BY name;


