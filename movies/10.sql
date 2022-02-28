SELECT name FROM people WHERE id in(
SELECT DISTINCT person_id from directors where movie_id IN(
SELECT movie_id from ratings WHERE rating >= 9));