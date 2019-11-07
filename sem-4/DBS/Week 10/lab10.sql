set serveroutput on;

--Q1
create table log_change_takes
(
	time_of_change date,
	course_id varchar(5),
	sec_id varchar(8),
	semester varchar(8),
	yr number(4),
	grade varchar(2)
);

create or replace trigger logging_takes
before insert or update on takes
for each row

begin

	case 
	when inserting then
		insert into log_change_takes 
		values (sysdate(), :OLD.course_id, :OLD.sec_id, :OLD.semester, :OLD.year, :OLD.grade);
	when updating then
		insert into log_change_takes 
		values (sysdate(), :OLD.course_id, :OLD.sec_id, :OLD.semester, :OLD.year, :OLD.grade);
	end case;
end;
/

--Q2 (error)
create or replace trigger upd_bal_st
before insert or update on item_transaction
for each row

begin

	case 
	when inserting then
		update item_master set balancestock = balancestock + :NEW.quantity
		where item_id = :NEW.item_id;
	end case;
end;
/

--Q3


--Q4

