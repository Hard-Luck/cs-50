SELECT * FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
where name LIKE "Kevin Bacon" and birth = 1958;


