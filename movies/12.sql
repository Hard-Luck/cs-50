SELECT * FROM stars
JOIN people ON stars.person_id = people.id
where name LIKE "Johnny Depp";
