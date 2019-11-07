set serveroutput on;

--Q1
drop table areas;
create table areas
(
	radius numeric(5, 2),
	area numeric(8, 2)
);
declare
	r numeric(5, 2);
	a numeric(8, 2);
begin
	insert into areas values (2, 12.56);
	insert into areas values (3 , 28.27);
	insert into areas values (3, 29);
	insert into areas values (4, 50.26);
	select radius, area into r, a from areas
	where radius = 3;
	dbms_output.put_line('Radius = ' || r);
	dbms_output.put_line('Area = ' || a);
exception
	when NO_DATA_FOUND then 
	dbms_output.put_line('No Values found');
	when TOO_MANY_ROWS then
	dbms_output.put_line('More than 1 row found');
end;
/


--Q3
drop table salesmanmaster;
drop table commission;
create table salesmanmaster
(
	salesmanNO numeric(3),
	salesmanname varchar(220),
	rate_of_com float,
	target_sales float,
	tot_sales float
);

insert into salesmanmaster values (1, 'Nishant', .4, 10000, 8000);
insert into salesmanmaster values (2, 'Pushar', .09, 590000, 7600);
insert into salesmanmaster values (3, 'Sneha', .001, 10000, 65000);
insert into salesmanmaster values (4, 'Nupur', .15, 280000, 8900000);

create table commission
(
	salesmanNO numeric(3),
	comm_amt float,
	dop date
);

declare
	tar_s float;
	tot_s float;
	s_no numeric(3);
	roc float;
	ex1 EXCEPTION;
begin
	select salesmanNo, target_sales, total_sales, rate_of_com into s_no, tar_s, tot_s, roc from salesmanmaster where salesmanNO = &x;

	if tar_s > tot_s then
		raise ex1;
	else
		insert into commission values (s_no, tot_s * roc, sysdate());
	end if;
exception
	when ex1 then
		dbms_output.put_line('Target not achieved');
end;
/

select * from fntable;		

--Q4
create table salaryraise
(
	inst_id instructor.id%type,
	raise_date date,
	raise_amt instructor.salary%type
);

declare
	temp instructor%rowtype;
	cursor c1 is select * from instructor where dept_name = 'Comp. Sci');
	amt number(8);
begin
	open c1 :
	loop
		fetch c1 into temp;
		exit when c1%NOTFOUND;
		update instructor set salary = 1.05 * salary
		where id = temp.id;
		raise_amt = temp.salary * 1.05;
		insert into salaryraise values (temp.id, sysdate, raise_amt);
	end loop
	close c1
end;
/

select * from salaryraise;

--Q5
declare
	cursor c1 is select * from student order by id;
	temp student%rowtype;
begin
	open c1 :
	loop
		fetch c1 into temp;
		dbms_output.put_line(temp.name || '   ' || temp.id || '   ' || temp.tot_credits);
		exit when c1%ROWCOUNT > 10
	end loop;
	close c1;
end;
/