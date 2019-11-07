set serveroutput on;

--Q1
create table Areas
(
	radius number,
	area numeric(5, 2)
);

insert into Areas values (2, 12.56);
insert into Areas values (3, 28.27);
insert into Areas values (4, 50.26);
insert into Areas values (6, 113.1);

declare
	
	rad areas.radius%TYPE;
	inp areas.radius%TYPE := &compRad;
	area1 areas.area%type;

begin

	select radius, area into rad, area1
	from areas
	where radius = inp;

	DBMS_OUTPUT.PUT_LINE('The area for radius ' || rad || ' is ' || area1);

EXCEPTION

WHEN NO_DATA_FOUND THEN DBMS_OUTPUT.PUT_LINE('No data was found');

end;
/

--Q2

--Q3
create table Salesman_Master
(
	salesman_no numeric(5, 0) primary key,
	saleman_name varchar(30),
	rate_of_commission numeric(4, 2),
	target_sales number,
	total_sales number
);

create table commission_payable
(
	salesman_no numeric(5, 0),
	commission number,
	date_of_payment date,
	constraint c foreign key(salesman_no) references Salesman_Master
);

insert into salesman_master
	values(12345, 'ABC', 5, 300000, 400000);
insert into salesman_master
	values(15232, 'DEF', 10, 500000, 400000);
insert into salesman_master
	values(18346, 'IQWT', 1.13, 60000, 70000);
insert into salesman_master
	values(98236, 'OAKDS', 2.64, 5000, 5000);
insert into salesman_master
	values(89624, 'JKAHSF', 1.98, 30000, 31000);
insert into salesman_master
	values(68923, 'KJBVS', 2, 1000000, 700000);

declare
	
	exc exception;
	inp salesman_master.salesman_no%type := &salesman_number;
	tot_sales salesman_master.total_sales%type;
	target salesman_master.target_Sales%type;
	comm commission_payable.commission%type;
	rate salesman_master.rate_of_commission%type;

begin

	select total_sales, target_Sales, rate_of_commission into tot_sales, target, rate
	from salesman_master
	where salesman_no = inp;

	if tot_sales > target THEN
		comm := rate * tot_sales / 100;
		insert into commission_payable
			values(inp, comm, sysdate());
	else
		raise exc;
	end if;

exception
	WHEN exc THEN DBMS_OUTPUT.PUT_LINE('Target has not been reached');

	WHEN NO_DATA_FOUND THEN DBMS_OUTPUT.PUT_LINE('The salesman doesnt exist');
end;
/

--Q4
create table salary_raise
(
	ins_id varchar(5),
	raise_date date,
	raise_amt numeric(8, 2)
);

declare
	
	input instructor.dept_name%TYPE := '&dept_name';
	CURSOR c1 is
		SELECT id, salary FROM instructor
		WHERE dept_name = input;
	ins_id instructor.id%TYPE;
	sal instructor.salary%TYPE;
	amt instructor.salary%TYPE;

begin

	open c1;
		loop
			FETCH c1 into ins_id, sal;
			EXIT when c1%NOTFOUND;
			amt := 0.05 * sal;
			update instructor set salary = 1.05 * salary
				where id = ins_id;

			insert into salary_raise
				values(ins_id, sysdate(), amt);
		end loop;

	close c1;

end;
/

--Q5
declare
	
	cursor c1 is
		select * from student2
		order by tot_cred;

	i number:= 10;
	s_id student2.id%type;
	s_n student2.name%type;
	s_d student2.dept_name%type;
	cred student2.tot_cred%type;

begin

	open c1;

		while i > 0
		loop
			fetch c1 into s_id, s_n, s_d, cred;
			DBMS_OUTPUT.put_line(s_id || ', ' || s_n || ', ' || s_d || ', ' || cred);
			i := i - 1;
		end loop;
	close c1;
end;
/
