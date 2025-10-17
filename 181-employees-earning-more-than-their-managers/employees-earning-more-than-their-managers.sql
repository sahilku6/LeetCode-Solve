# Write your MySQL query statement below
SELECT e.name as Employee
from Employee e
join Employee m
on e.managerid=m.id
where e.salary>m.salary;

