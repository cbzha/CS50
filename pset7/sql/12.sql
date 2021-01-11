SELECT title FROM(people JOIN stars ON people.id = stars.person_id JOIN movies ON movies.id = stars.movie_id) WHERE name = 'Johnny Depp' AND title in (SELECT title FROM(people JOIN stars ON people.id = stars.person_id JOIN movies ON movies.id = stars.movie_id) WHERE name = 'Helena Bonham Carter');

