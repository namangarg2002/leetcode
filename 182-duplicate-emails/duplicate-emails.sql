# Write your MySQL query statement below
-- select email as Email
-- from Person
-- group by email
-- having count(*) > 1;

select distinct p1.email as Email
From Person p1, Person p2
where p1.email=p2.email and p1.id<>p2.id;