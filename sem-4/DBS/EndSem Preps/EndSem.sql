--LAB2
select name, dept_name from student2;

select * from instructor
where dept_name = 'Comp. Sci.';

select title from course
where credits = 3;

select id, course_id, title from takes natural join course
where id = 12345;

select * from instructor
where salary between 40000 and 90000;

update advisor set I_id = 83821
where s_id in (45678, 76653);

update instructor set dept_name = 'Comp. Sci.'
where dept_name = 'Finance';

update instructor set salary = salary * 1.05;

delete from instructor
where dept_name = 'Music';
delete from department
where dept_name = 'Music';

delete from prereq where course_id = 'BIO-301';

alter table student2 add DOB date;

alter table department modify dept_name varchar(20);

alter table student2 drop column DOB;

select id from instructor
where id not in (select id from teaches);

select id from takes join section using (course_id)
where room_number = 100;

select name, course_id c_name from student2 natural join takes
where year = 2009;

select name, salary inst_sal from instructor
where salary > (select min(salary) from instructor
					where dept_name = 'Comp. Sci.');

select * from instructor
where dept_name like '%si%';

--20 (not full)
select course_id, title from prereq natural join course
	order by course_id, title desc;			

--Addl
select distinct dept_name from instructor;

select distinct id, name, course_id from instructor natural join teaches
order by id;

--(3rd is similar to 2nd)

select s.id stu_ID , s.name stu_name, s.dept_name stu_dept, i.name adv_name
from student2 s join advisor a on s.id = a.S_id join instructor i on i.id = a.i_id;


--LAB3

--first 3 easy and bored
select dept_name, avg(salary) avg_salary from instructor
where dept_name = 'Comp. Sci.';

select count(id) from teaches
where semester = 'Spring' and year = 2010;

select course_id, count(id) from takes
group by course_id;

select dept_name from (select count(id) c, dept_name from student2 group by dept_name)
where 1 < c;

select dept_name, count(course_id) from course
group by dept_name;

select dept_name, avg(salary) avg_sal from instructor
group by dept_name having avg(salary) > 70000 ;

select course_id from course
where course_id not in (select distinct course_id from takes);
--or
select course_id from course
minus
select distinct course_id from takes;

select course_id from teaches
where semester = 'Fall' and year = 2009 and course_id in
(select course_id from teaches
where semester = 'Spring' and year = 2010);

--similar to previous

select count(id) from takes
where course_id in (select distinct course_id from teaches
where id = 10101);

select name, salary from instructor
where salary >some (select salary from instructor where dept_name = 'Biology');

select name, salary from instructor
where salary >all (select salary from instructor where dept_name = 'Finance');

select course_id from teaches S
where semester = 'Fall' and year = 2009 and exists (select course_id from teaches T
where semester = 'Spring' and year = 2010 and T.course_id = S.course_id);

--37 referred from book

select course_id from section
where unique (select course_id from section where year = 2009);

--continuing from 40

select max(tot) max_sal from 
	(select sum(salary) tot, dept_name from instructor
	group by dept_name);

select dept_name, avg_sal from 
	(select avg(salary) avg_sal, dept_name from instructor
	group by dept_name)
where avg_sal > 70000;

select dept_name, budget from department
where budget = (select max(budget) from department);

--copied from book
with tab(tot_sal, dept_name) as 
	(select sum(salary), dept_name from instructor 
		group by dept_name),
		 dept_tot_avg(value) as 
		 (select avg(tot_sal) from tab)
select tab.dept_name from tab, dept_tot_avg
where tab.tot_sal > dept_tot_avg.value;

create view all_courses as 
	(select course_id, building, room_number from section natural join course
		where dept_name = 'Physics');

create view dept_tot_sal as
	(select dept_name, sum(salary) tot_sal from instructor
	 group by dept_name);

savepoint s1;

delete from instructor where dept_name = 'Finance';

delete from course where dept_name = 'Comp. Sci.';

update student2 set dept_name = 'IT' where dept_name = 'Comp. Sci.';

update instructor set salary = 1.03 * salary where salary > 100000;
update instructor set salary = 1.05 * salary where salary <= 100000;

insert into student2 select id, name, dept_name, 0 from instructor;

delete from instructor 
	where salary < (select avg(salary) from instructor);

rollback to s1;

--addl.
with cnt_course(course_id, count) as 
(select course_id, count(id) from takes
group by course_id)
select course_id, title, count from course natural join cnt_course
where count > 3;

--4
select name from student2 S
where not exists ((select course_id from course
					where dept_name = 'Elec. Eng.')
					MINUS
					(select course_id from takes
					where id = S.id)
					);


--LAB4
--from q10

select name, length(name) from student2;

select lower(name) from instructor;

select dept_name, substr(dept_name, 3, 3) from department;

select upper(name) from instructor;

update takes set grade = nvl(grade, 0);

select empname, to_char(DOB, 'DD-MON-YY') DOB from employee;
sselect empname, to_char(DOB, 'DD-MM-YY') DOB from employee;

select empname, to_char(DOB, 'DAY') from Employee;
select empname, to_char(DOB, 'Day') from Employee;

select empname, to_char(DOB, 'MONTH') from Employee;
select empname, to_char(DOB, 'Month') from Employee;

select empname, last_day(DOB), to_char(last_day(dob), 'DAY') from employee
where empname like '%Nishant%';

select empname, extract(year from sysdate) - extract(year from DOB) AGE from employee;

select Next_day((DOB + 60 * 365.25), 'Saturday') from employee;

select empname from employee
where extract(year from dob) = 1955;

select empname from employee
where extract(year from dob) between 1980 and 2000;

select empname from employee
where extract(year from (DOB + 60 * 365.25)) = 2058;


--addl.
alter table employee add constraint sal check (salary > 5000);

select empname, dob, round(to_char(DOB, 'MM')/3, 0) quarter from employee;

--lab6 addl.

--9
declare

    yr number(4) := &year;
    temp number(4);

begin

    if mod(yr, 4) = 0 then
        if mod(yr, 400) = 0 then
            goto leap;
        elsif mod(yr, 100) = 0 then goto noleap;
        else 
            goto leap;
        end if;
    else
        goto noleap;
    end if;

<<noleap>>
DBMS_OUTPUT.PUT_LINE('The year ' || yr || ' is not a leap year');
goto endl;
<<leap>>
DBMS_OUTPUT.PUT_LINE('The year ' || yr || ' is a leap year');
<<endl>>
DBMS_OUTPUT.PUT_LINE('');
end;
/

--13
declare

    str varchar(20) := '&string';
    rev varchar(20);
    len int;

begin


    len := length(str);

    while len > 0
    loop
        rev := rev || substr(str, len, 1);
        len := len - 1;
    end loop;

    DBMS_OUTPUT.PUT_LINE('The reversed string is ' || rev);
end;
/

--14 (not proper)
declare
    
    num int := &num;
    revnum int;
    temp int;

begin

    temp := num;
    revnum := 0;

    while temp > 0 
    loop
        revnum := (revnum * 10) + remainder(temp, 10);
        temp := temp / 10;
    end loop;

    dbms_output.put_line('The reverse of ' || num || ' is ' || revnum);
end;
/

declare
    
    NO_OP exception;
    num1 int := &num1;
    num2 int := &num2;
    res int;
    op char := '&operator';

begin

    if op = '+' then
        res := num1 + num2;
    elsif op = '-' then
        res := num1 - num2;
    elsif op = '*' then
        res := num1 * num2;
    elsif op = '/' then
        res := num1 / num2;
    else 
        raise NO_OP;
    end if;

    DBMS_OUTPUT.PUT_LINE('The result is ' || res);

exception
    when NO_OP then 
        DBMS_OUTPUT.PUT_LINE('The operator is invalid');
    when ZERO_DIVIDE then
        DBMS_OUTPUT.PUT_LINE('Divide by zero error');
end;
/

create view temp as select * from course natural join teaches
         natural join section natural join time_Slot;

declare

    cursor c1 is
        select * from temp;

    item temp%rowtype;
begin
    
    for item in c1
    loop
        dbms_output.put_line(item.course_id || ', ' || item.title || ', ' || item.dept_name || ', ' || item.credits|| ', ' || item.building || ', ' || item.room_number || ', ' || item.time_slot_id);
    end loop;

end;
/

create view v1 as
    select * from takes natural join student2
        where course_id = 'CS-101';

declare
    cursor c1 is
        select * from v1;

    row v1%rowtype;

begin
    
    for row in c1
    loop
        if row.tot_cred < 50 then
            delete from takes 
                where id = row.id and course_id = 'CS-101';
        end if;
    end loop;

end;
/

--LAB9

create or replace package pckg1 as

    procedure inst_dept;

    function max_sal(dept instructor.dept_name%type)
    return number;

end pckg1;
/

--errors
