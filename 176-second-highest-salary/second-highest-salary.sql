select(select max(salary) from employee
where salary not in (select max(salary) from employee))as SecondHighestSalary; 