SELECT * from stars WHERE person_id =
(SELECT id from people WHERE name LIKE "Johnny Depp")

--select title from movies where id IN(