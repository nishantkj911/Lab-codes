set serveroutput on;

--Q1
DROP TABLE salary_raise;
CREATE TABLE salary_raise 
(
	I_Id varchar(5), 
	raise_date date, 
	amt number(8,2)
);

declare
	temp instructor%rowtype;
	CURSOR cur IS SELECT * FROM instructor where dept_name = dname for update;
	sal_raise number(8,2);
	
begin
	open c1
	for temp in cur
	loop
		update instructor set salary = salary * 1.05 
		where dept_name = dname;

		sal_raise := temp.salary * 0.05;

		insert into salary_raise values
		(temp.id, (SELECT sysdate FROM dual), sal_raise) 
		where current of cur;

		exit when cur%NOTFOUND;
	end loop;
end;
/

--Q2
CREATE TABLE Item_Master 
(
	itemid int primary key, 
	descrption varchar(50), 
	balanceStock int
);

CREATE TABLE Item_Transaction 
(
	itemid int primary key, 
	descrption varchar(50), 
	quantity int
);

INSERT INTO Item_Master VALUES (1, 'Kryptonite Balls', 10);
INSERT INTO Item_Master VALUES (2, 'Batrangs', 200);
INSERT INTO Item_Master VALUES (3, 'Smoke Bombs', 100);

DECLARE

	CURSOR curse(item int) IS
		SELECT * FROM Item_Master WHERE itemid = item FOR UPDATE;

	rowItemMaster Item_Master%ROWTYPE;
	itemid int;
	desc varchar(50);
	qty int;
	flag int := 0;

BEGIN

	itemid := &id;
	des := &des;
	qty := &qty;

	OPEN curse(itemid);

	FETCH curse INTO rowItemMaster;
	INSERT INTO Item_Transaction VALUES (itemid, des, qty);
	IF curse%NOTFOUND THEN
		INSERT INTO Item_Master VALUES (itemid, des, qty);
		dbms_output.put_line('Item Not Available');
	ELSE
		UPDATE Item_Master SET balanceStock = balanceStock - qty WHERE itemid = id;
	END IF;

END;

/

SELECT * FROM Item_Master;
SELECT * FROM Item_Transaction;

--Q3
DECLARE

	tsal numeric;

BEGIN

	SAVEPOINT salInc;

	UPDATE Instructor SET salary = 100000 
		WHERE name LIKE '%Mozart%';
	
	UPDATE Instructor SET salary = 150000 
		WHERE name LIKE '%Srinivasan%';

	SELECT SUM(salary) INTO tsal FROM Instructor;
	IF tsal > 2000000 THEN
		ROLLBACK TO SAVEPOINT salInc;
		DBMS_OUTPUT.PUT_LINE('ROLLBACKED!');
	END IF;

END;
/