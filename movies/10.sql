SELECT DISTINCT person_id where movie_id IN(
SELECT movie_id from ratings WHERE rating >= 9);