SELECT movie_id from stars WHERE person_id IN ((
SELECT id from people WHERE name LIKE "Johnny Depp")
AND(
SELECT id from people WHERE name LIKE "Helena Bonham Carter"));