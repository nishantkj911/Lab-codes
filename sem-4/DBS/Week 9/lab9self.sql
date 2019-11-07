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

--Q4

--Q5

--Q6

--Q7

--Q8

--Q9