SELECT movies.title, ratings.rating
FROM movies
WHERE movies.year = 2010
INNER JOIN ratings ON movies.id = ratings.movie_id;