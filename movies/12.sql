SELECT * from stars WHERE (person_id =
(SELECT id from people WHERE name LIKE "Johnny Depp") AND person_id =
(SELECT id from people WHERE name LIKE "Helena Bonham Carter"))  ;

--select title from movies where id IN(