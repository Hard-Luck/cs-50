SELECT movie_id from stars WHERE person_id IN (
SELECT id from people WHERE name LIKE "Johnny Depp" AND
"HELENA BONHAM CARTER");

--select title from movies where id IN(