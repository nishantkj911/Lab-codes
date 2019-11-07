--1
select bdate, address from employee
where fname = 'John' and mname = 'B' and lname = 'Smith';

select fname, mname, lname, address
from employee natural join department
where dname = 'Admin';

select pnum, project.dnum, lname, address, bdate from project, department, employee
where project.dnum = department.dnum and department.manid = employee.ssn and 
(pnum, project.dnum) in (select pnum, dnum from project where locid = 'NY');

select distinct salary from employee;

select E.fname, E.Lname, S.fname, S.lname
from employee E, employee S
where E.supssn = S.ssn;

--6
select pnum from workson natural join project P
where essn in (select w.essn from workson W, employee E
		where w.essn = e.ssn and e.lname = 'Smith')
		or dnum in
		(select D.dnum from department D, Employee F
		where D.manID = F.ssn and F.lname = 'Smith');

select * from employee
where address = 'Classified';

select essn, salary * 1.10 inc_salary 
from project p natural join workson w join employee e on w.essn = e.ssn
where pname = 'ProjectX';

select ssn, fname, mname, lname from employee
where dnum = 603 and salary between 100000 and 400000;



--11
select fname, mname, lname from employee
where supssn is null;

select fname, mname, lname 
from employee E, dependent D
where D.essn = e.ssn and D.gender = E.gender and D.name = E.fname;

select fname, mname, lname
from employee where ssn not in (select essn from dependent);

select fname, mname, lname
from employee
where ssn in (select department.manID from department join dependent on dependent.essn = department.manID);

select essn from workson
where pnum in (701, 702, 703);

--16
select sum(salary) tot_salary, max(salary) max_salary, min(salary) min_salary, avg(salary) avg_salary
from employee;

select sum(salary) tot_salary, max(salary) max_salary, min(salary) min_salary, avg(salary) avg_salary
from employee E natural join department D
where D.dname = 'Enforcement';

with proj(pno, count_emp) as (select pnum, count(essn) 
	from workson natural join project
	group by pnum) 
select pno, pname, count_emp
from Project join proj on proj.pno = project.pnum;

with pro(pnum, count) as (select pnum, count(essn) from workson
		group by pnum)
select pnum, pname, count from project natural join pro
where count > 2;

with temp(dnum, count) as (select dnum, count(ssn) 
	from department natural join employee
	where salary > 40000
	group by dnum)
select dnum, count from temp
where count > 1;