SELECT title FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
where name LIKE "Johnny Depp"

INTERSECT

SELECT title FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
where name LIKE "Helena Bonham Carter"
