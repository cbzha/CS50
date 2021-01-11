SELECT name FROM(people JOIN stars ON people.id = stars.person_id JOIN movies ON movies.id = stars.movie_id) WHERE title in (SELECT title FROM(people JOIN stars ON people.id = stars.person_id JOIN movies ON movies.id = stars.movie_id) WHERE name = 'Kevin Bacon' AND birth = 1958) AND not name = 'Kevin Bacon';

