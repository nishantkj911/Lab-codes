set serveroutput on;

--Q1
declare
	a number;
	b number;
	c number;
	D number;
	r1 float;
	r2 float;
	
begin
	a := &a;
	b := &b;
	c := &c;

	D := b * b - 4 * a * c;
	
	if D > 0 then
		r1 := (- b + sqrt(D)) / (2 * a);
		r2 := (- b - sqrt(D)) / (2 * a);
		DBMS_OUTPUT.PUT_LINE('The roots are ' || r1 || ' and ' || r2);
	elsif D = 0 then
		r1 := - b / (2 * a);
		DBMS_OUTPUT.PUT_LINE('Equal roots with value ' || r1);
	else 
		DBMS_OUTPUT.PUT_LINE('The roots are imaginary');
	end if;
end;
/

--Q2
declare
	indate date;
	outdate date;
	
	days number;
	fine numeric(5, 2);
	
begin
	indate := '&start_date';
	outdate := '&end_date';
	
	days := outdate - indate;
	
	if days < 5 then
		fine := 0;
	elsif days < 6 then
		fine := 0.5;
	elsif days < 10 then
		fine := 1;
	elsif days < 30 then
		fine := 5;
	else
		fine := 10;
		
	end if;
	
	DBMS_OUTPUT.PUT_LINE('The no of days are ' || days || ' and the fine is ' || fine);
end;
/

--Q3
declare
	num number;
	a number;
	b number;
	c number;

begin
	a := 0;
	b := 1;
	num := &max_fib;
	
	DBMS_OUTPUT.PUT_LINE('The fibonacci numbers are:');
	DBMS_OUTPUT.PUT_LINE(a);
	DBMS_OUTPUT.PUT_LINE(b);
	
	loop
	
	c := a + b;
	a := b;
	b := c;
		
		EXIT when c > num;
	DBMS_OUTPUT.PUT_LINE(c);
	end loop; 
	
end;
/

--Q4
declare
	num  int;
	temp int;
	rev int;

begin

	num := &the_number;
	temp := num;
	rev := 0;

	while temp > 0
	loop
		rev := (rev * 10) + remainder(temp, 10);
		temp := temp / 10;	
	end loop;
	
	dbms_output.put_line('The reverse of the number is ' || rev);
	
	if rev = num then
		dbms_output.put_line('The number ' || num || ' is a palindrome');
	else
		dbms_output.put_line('The number ' || num || ' is not a palindrome');
		
	end if;

end;
/


--Q5
set serveroutput on;

create table TBL_NEXT_DATE
(
	given_Date date,
	next_Date date
);

declare 
	
	type arr is varray(5) of date;
	ds arr;
	num int;

begin
	ds := arr('&a', '&b', '&c', '&d', '&e');
	num := ds.count;

	for i in 1..num
	loop
		insert into tbl_next_date 
			values (ds(i), ds(i)+1);
	end loop;

end;
/

select * from TBL_NEXT_DATE;

--Q6
create table sphere
(
	radius number,
	volume numeric(6, 2),
	surface_area numeric(6, 2)
);

declare
	llimit number;
	ulimit number;
	vol numeric(6, 2);
	sa numeric(6, 2);
	pi constant number := 3.141592654;  

begin
	llimit := &lower_limit;
	ulimit := &upper_limit;

	for i in llimit..ulimit
	loop
		vol := 4 * i * i * i * pi / 3;
		sa := 4 * i * i * pi;

		insert into sphere values
			(i, vol, sa);
	end loop;

end;
/

select * from sphere;

--Q7
declare
	num int;
	fact int;
begin
	fact := 1;
	num := &number;
	for i in 2..num
	loop
		fact := fact * i;
	end loop;
	dbms_output.put_line('The factorial of ' || num || ' is ' || fact);
end;
/

--Q8
declare
	avg1 float;
	total number;
	cnt number;
	inp int;

begin
	total := 0;
	cnt := 0;

	loop
		inp := &num;
		if inp = -1 then 
			;
		end if;

		total := total + inp;
		cnt := cnt + 1;
	end loop;

	avg1 := total / cnt;

	DBMS_OUTPUT.PUT_LINE('The average is ' || avg1);
end;
/