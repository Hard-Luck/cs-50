SELECT movie_id from stars WHERE person_id IN (
SELECT id from people WHERE name IS "Johnny Depp")
AND(
SELECT id from people WHERE name IS "Helena Bonham Carter");