set serveroutput on;

--Q1
declare

	item instructor%rowtype;
	amt instructor.salary%type;
	cursor c1 is
		select * from instructor
		where dept_name = '&dept_name';

begin

	for item in c1
	loop
		amt := 0.05 * item.salary;
		update instructor set salary = 1.05 * salary
			where id = item.id;
		insert into salary_raise
			values(item.id, sysdate(), amt);
	end loop;

end;
/


--Q2

--Q3