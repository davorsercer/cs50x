/* In 10.sql, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
Your query should output a table with a single column for the name of each person.
If a person directed more than one movie that received a rating of at least 9.0, they should only appear in your results once.

Notice that this query, like the previous, requires you to use data from multiple tables. Recall that you can “nest” queries in SQL, which allows you to break a larger query into smaller ones. Perhaps you could write queries to…
Find the IDs of movies with at least a 9.0 rating
Find the IDs of people who directed those movies
Find the names of people with those people IDs
Then, try nesting those queries to arrive at a single query that returns the names of all people who have directed a movie that received a rating of at least 9.0.

Executing 10.sql results in a table with 1 column and 4,726 rows. */

SELECT name
  FROM people
 WHERE id IN
(
    SELECT person_id
      FROM directors
     WHERE movie_id IN
    (
        SELECT movie_id
          FROM ratings
         WHERE rating >= 9
    )
);
