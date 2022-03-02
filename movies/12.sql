SELECT movie_id from stars WHERE person_id IN (
SELECT id from people WHERE name LIKE "Johnny Depp" UNION
SELECT id from people WHERE name LIKE "HELENA BONHAM CARTER");

--select title from movies where id IN(