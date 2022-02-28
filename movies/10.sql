SELECT person_id FROM stars WHERE person_id in(
SELECT DISTINCT person_id from directors where movie_id IN(
SELECT movie_id from ratings WHERE rating >= 9));