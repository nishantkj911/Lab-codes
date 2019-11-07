drop table employee;
drop table department;
drop table Project;
drop table workson;
drop table dependent;
drop table locations;

create table Employee
(
	SSN number(6) primary key,
	Fname varchar(10) not null,
	Mname varchar(10),
	Lname varchar(10) not null,
	Address varchar(20),
	Salary number(10) check (salary > 0),
	gender char(1) not null check (Gender in ('M', 'F')),
	SupSSN number(6),
	DNum number(5)
	BDate date
);

create table Department
(
	Dnum number(5) primary key,
	Dname varchar(30) unique not null,
	ManID number(6) not null,
	StartDate date not null
);

create table Dependent
(
	ESSN number(6),
	Name varchar(30) unique not null,
	gender char(1) not null check (gender in ('M', 'F')),
	Relationship varchar(30),
	BDate date,
	constraint Depen_pk primary key(ESSN, name)
);

create table Project
(
	Pnum number(4) primary key,
	PName varchar(30) not null,
	LocID varchar(20),
	DNum number(5)
);

create table WorksOn
(
	ESSN number(5),
	PNum number(4), 
	Hours number(3)
);

create table Locations
(
	LocID varchar(20),
	DNum number(5),
	primary key(LocID, Dnum)
);

alter table employee add constraint supervision 
foreign key(supssn) references employee(ssn);

alter table employee add constraint worksfor
foreign key(Dnum) references department(dnum);

alter table project add constraint controls
foreign key(Dnum) references department;

alter table dependent add constraint dependent_of
foreign key(essn) references employee(ssn);

alter table workson add constraint wor_emp
foreign key(essn) references employee(ssn);

alter table workson add constraint wor_pro
foreign key(pnum) references project;

insert into Employee (fname, mname, lname, ssn, address, bdate, gender, salary, supssn, dnum) 
	values ('Harold', 'J', 'Finch', 101, 'Classified', '10-NOV-61', 'M', 192000, null, 601);
insert into Employee (fname, mname, lname, ssn, address, bdate, gender, salary, supssn, dnum)
	values ('John', 'B', 'Smith', 102, '5th Avenue, NY', '21-FEB-72', 'M', 112000, 101, 603);
insert into Employee (fname, mname, lname, ssn, address, bdate, gender, salary, supssn, dnum)
	values ('Sameen', 'R', 'Shaw', 103, '4th Loop, NY', '18-DEC-78', 'F', 112000, 101, 603);
insert into Employee (fname, mname, lname, ssn, address, bdate, gender, salary, supssn, dnum
	values ('Samantha', 'R', 'Groves', 104, '1, Infinite Loop', '08-APR-79', 'F', 250000, null, 602);
insert into Employee (fname, mname, lname, ssn, address, bdate, gender, salary, supssn, dnum)
	values ('Lionel', 'P', 'Fusco', 105, '18th Rose Drive', '10-JUN-68', 'M', 89000, 104, 606);
insert into Employee (fname, mname, lname, ssn, address, bdate, gender, salary, supssn, dnum)
	values ('John', 'F', 'Greer', 106, 'Classified', '28-DEC-51', 'M', 800000, null, 609);
insert into Employee values 
	(108, 'Robert', 'D', 'Jr.', 'Upstate', 10000000, 'M', null, 606, '22-APR-1976');

insert into Department (Dname, dnum, manid, startdate) 
	values ('Admin', 601, 101, '02-JAN-03');
insert into Department (Dname, dnum, manid, startdate) 
	values ('Machine Field', 603, 102, '02-MAY-11');
insert into Department (Dname, dnum, manid, startdate) 
	values ('Analog Interface', 602, 104, '02-JAN-03');
insert into Department (Dname, dnum, manid, startdate) 
	values ('Enforcement', 606, 105, '02-JAN-78');
insert into Department (Dname, dnum, manid, startdate) 
	values ('Samaritan', 609, 106, '02-DEC-13');

alter table department add constraint manages 
foreign key(manID) references employee(ssn);

insert into Locations (Dnum, locId) values (601, 'Classified');
insert into Locations (Dnum, locId) values (602, 'Thornhill');
insert into Locations (Dnum, locId) values (603, 'NY');
insert into Locations (Dnum, locId) values (606, 'Brooklyn 99');
insert into Locations (Dnum, locId) values (609, 'Texas');


insert into Project (pNAME, Pnum, Locid, dnum) 
	values ('ProjectX', 701, 'NY', 601);
insert into Project (pNAME, Pnum, Locid, dnum) 
	values ('ProjectY', 702, 'FR', 602);
insert into Project (pNAME, Pnum, Locid, dnum) 
	values ('ProjectZ', 703, 'TX', 603);
insert into Project (pNAME, Pnum, Locid, dnum) 
	values ('ProjectW', 704, 'CA', 609);

insert into WorksOn values (101, 701, 32);
insert into WorksOn values (102, 702, 16);
insert into WorksOn values (103, 702, 16);
insert into WorksOn values (104, 704, 40);
insert into WorksOn values (105, 702, 25);
insert into WorksOn values (106, 701, 35);
insert into WorksOn values (108, 703, 25);

insert into Dependent (essn, name, gender, bdate, relationship) 
	values (101, 'Harold', 'M', '10-OCT-01', 'Pet');
insert into Dependent (essn, name, gender, bdate, relationship) 
	values (102, 'World', 'M', '10-OCT-01', 'Protector');
insert into Dependent (essn, name, gender, bdate, relationship) 
	values (103, 'Jakku', 'M', '10-OCT-01', 'Protector');
insert into Dependent (essn, name, gender, bdate, relationship) 
	values (104, 'Machine', 'M', '02-JAN-03', 'Interface');
