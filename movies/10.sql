SELECT DISTINCT id from people where movie_id IN(
SELECT movie_id from ratings WHERE rating >= 9);