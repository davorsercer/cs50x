/*
In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
Your query should output a table with a single column for the name of each person.
There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
Kevin Bacon himself should not be included in the resulting list.

Notice that this query, like the previous, requires you to use data from multiple tables. Recall that you can “nest” queries in SQL, which allows you to break a larger query into smaller ones. Perhaps you could write queries to…

Find the ID of Kevin Bacon (the one born in 1958!)
Find the IDs of movies associated with Kevin Bacon’s ID
Find the IDs of people associated with those movie IDs
Find the names of people with those people IDs
Then, try nesting those queries to arrive at a single query that returns the names of all people who starred in a movie in which Kevin Bacon also starred. Keep in mind that you’ll want to exclude Kevin Bacon himself from the results!

Executing 13.sql results in a table with 1 column and 553 rows.
*/

SELECT name FROM people WHERE id IN
(SELECT person_id FROM stars WHERE movie_id IN
(SELECT movie_id FROM stars WHERE person_id =
(SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958)))
AND name != 'Kevin Bacon'
;
