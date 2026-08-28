with rank_table as(
    select e.name as Employee, e.salary as Salary, d.name as Department, DENSE_RANK() over (partition by e.departmentId order by salary DESC) as rk from Employee e
    join Department d on d.id = e.departmentId 
)
select Department, Employee, Salary from rank_table where rk <= 3;