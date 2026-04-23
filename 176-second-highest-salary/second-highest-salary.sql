-- select(select max(salary) from employee
-- where salary not in (select max(salary) from employee))as SecondHighestSalary; 


SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;