/*
In 12.sql, write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Bradley Cooper.
You may assume that there is only one person in the database with the name Jennifer Lawrence.

Notice that this query, like the previous, requires you to use data from multiple tables. Recall that you can “nest” queries in SQL, which allows you to break a larger query into smaller ones. Perhaps you could write queries to…

Find the ID of Bradley Cooper
Find the ID of Jennifer Lawrence
Find the IDs of movies associated with Bradley Cooper’s ID
Find the IDs of movies associated with Jennifer Lawrence’s ID
Find movie titles from the movie IDs associated with both Bradley Cooper and Jennifer Lawrence
Then, try nesting those queries to arrive at a single query that returns the movies in which both Bradley Cooper and Jennifer Lawrence starred.

Recall that you can build compound conditions in SQL using AND or OR.

Executing 12.sql results in a table with 1 column and 4 rows.
*/

--/*
SELECT title
  FROM movies
 WHERE id IN
(
    SELECT movie_id
      FROM stars
     WHERE person_id IN
    (
        SELECT id
          FROM people
         WHERE name = 'Bradley Cooper'
    )
)
   AND title IN
(
    SELECT title
    FROM movies
    WHERE id IN
    (
        SELECT movie_id
        FROM stars
        WHERE person_id IN
        (
            SELECT id
            FROM people
            WHERE name = 'Jennifer Lawrence'
        )
    )
)
;
--*/

/* SELECT title
  FROM movies
  JOIN stars ON stars.movie_id = movies.id
  JOIN people ON people.id = stars.person_id
 WHERE people.name = 'Bradley Cooper'
   AND title IN
(
    SELECT title
      FROM movies
      JOIN stars ON stars.movie_id = movies.id
      JOIN people ON people.id = stars.person_id
     WHERE people.name = 'Jennifer Lawrence'
);
*/
