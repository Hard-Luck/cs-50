SELECT title FROM movies
JOIN stars on movies.id = stars.person_id
JOIN people ON stars.person_id = people.id
where name LIKE "Johnny Depp";
