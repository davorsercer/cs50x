/* In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Chadwick Boseman.

Notice that this query, like the previous, requires you to use data from multiple tables. Recall that you can “nest” queries in SQL, which allows you to break a larger query into smaller ones. Perhaps you could write queries to…

Find the ID of Chadwick Boseman
Find the IDs of movies associated with Chadwick Boseman’s ID
Find the movie titles with those movie IDs
Then, try nesting those queries to arrive at a single query that returns the titles of Chadwick Boseman’s movies.

Executing 11.sql results in a table with 1 column and 5 rows. */

-- /*
SELECT DISTINCT title
  FROM movies
  JOIN ratings ON ratings.movie_id = movies.id
  JOIN stars ON stars.movie_id = movies.id
  JOIN people ON people.id = stars.person_id
 WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
 LIMIT 5;
-- */

/*
SELECT DISTINCT title
  FROM movies
 WHERE id IN
(
    SELECT movie_id
      FROM ratings
     WHERE movie_id IN
    (
        SELECT movie_id
        FROM stars
        WHERE person_id =
        (
            SELECT id
            FROM people
            WHERE name = 'Chadwick Boseman'
        )
    )
ORDER BY rating DESC
)
LIMIT 5
;
*/
