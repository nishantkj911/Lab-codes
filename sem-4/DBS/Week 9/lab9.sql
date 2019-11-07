set serveroutput on;

--Q1
create or replace procedure firstproc is
begin
	
	DBMS_OUTPUT.PUT_LINE('Good day to you!');
end;
/

--Q2
create or replace procedure listing (dept student2.dept_name%type) is
	cursor c1 is
		select * from student2
		where dept_name = dept;
	temp student2%rowtype;
	temp2 course%rowtype;
	cursor c2 is
		select * from course
		where dept_name = dept;
begin

	DBMS_OUTPUT.PUT_LINE('The students in the ' || dept || ' department are');
	for temp in c1
	loop
		DBMS_OUTPUT.PUT_LINE(temp.name);
	end loop;
	DBMS_OUTPUT.PUT_LINE('The course offered by this dept. are');
	for temp2 in c2
	loop
		DBMS_OUTPUT.PUT_LINE(temp2.title);
	end loop;
end;
/

declare
begin
	listing('Finance');
end;
/
--Q3
create or replace procedure department_highest (dept department.dept_name%type)
is
	item course%rowtype;
	cursor c1 is 
		select * from instructor
		where dept_name = dept;
	max_sal instructor.salary%type;
	max_sal_id instructor.id%type;
	
begin
	max_sal := 0;
	max_sal_id := 0;
	for item in c1
	loop
		if item.salary >= max_sal then
			max_sal := item.salary;
			max_sal_id := item.id;
		end if;
	end loop;
	
	dbms_output.put_line('The person id with max salary in ' || dept || ' department is ' || max_sal_id);
end;
/

declare
	cursor c2 is 
		select * from department;
	item2 department%rowtype;
	
begin
	
	for item in c2
	loop
		department_highest(item.dept_name);
	end loop;
end;
/
--Q4

--Q5
set serveroutput on;

create or replace function sqr(num int)
return number as
	square int;
begin
	square := num * num;
	return square;
end;
/

declare
begin

	dbms_output.put_line(sqr(&num));
end;
/
--Q6

--Q7

--Q8

--Q9