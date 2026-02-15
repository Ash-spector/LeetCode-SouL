# Write your MySQL query statement below
select p.firstname,p.lastname , a.city, a.state
from person P
LEFT JOIN Address a ON p.personId = a.personId;
