drop table prereq;
drop table time_slot;
drop table advisor;
drop table takes;
drop table student;
drop table teaches;
drop table section;
drop table instructor;
drop table course;
drop table department;
drop table classroom;

create table course (
	course_id char(7) primary key,
	title varchar(30),
	dept_name varchar(30), 
	credits int,
);

create table classroom (
	building char(3),
	room_no int,
	capacity int,
	primary key(building, room_no)
);

create table department (
	dept_name varchar(30) primary key,
	building char(3),
	budget int
);

create table student (
	ID int primary key,
	name varchar(30),
	dept_name varchar(30),
	tot_cred int,
	foriegn key(dept_name) references department
);

create table instructor (
	ID int primary key,
	name varchar(30),
	dept_name varchar(50),
	salary int,
	foreign key(dept_name) references department
);

create table section (
	course_id char(7),
	section_id char(2),
	semester int,
	year int,
	building char(3),
	room_no int,
	time_slot_id int references time_slot_id,
	primary key(course_id, section_id, semester, year),
	foreign key(building, room_no) references classroom
);

create table takes (
	ID int,
	course_id char(7),
	sec_id char(1),
	semester int,
	year int,
	grade char(1)
	primary key (ID, course_id, sec_id, semester, year)
	foreign key (course_id, sec_id, semester, year) references section
);

create table teaches (
	id int,
	course_id char(7),
	sec_id char(2),
	semester int,
	year int,
	primary key (id, course_id, sec_id, semester, year),
	foreign key(course_id, sec_id, semester, year) references section
);

create table advisor (
	s_id int primary key,
	i_id int,
	foreign key(s_id) references student(ID),
	foreign key(s_id) references instructor(ID),
);

create table time_slot (
	time_slot_id int,
	day char(9),
	start_time int,
	end_time int,
);

create table prereq (
	course_id char(7),
	prereq_id char(7),
	foreign key(course_id, prereq_id) references course
);
		