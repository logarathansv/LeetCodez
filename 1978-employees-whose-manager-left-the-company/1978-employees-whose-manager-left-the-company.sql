select e.employee_id from Employees e
where salary < 30000 
AND e.manager_id NOT IN (
    select employee_id from Employees
) ORDER BY e.employee_id;