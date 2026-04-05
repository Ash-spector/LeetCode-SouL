select employee_id 
from Employees
where (salary < 30000 and manager_id NOT IN(select employee_ID from Employees))
order by employee_id