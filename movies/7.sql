SELECT title from movies
JOIN ratings
on movies.id = ratings.movie_id;