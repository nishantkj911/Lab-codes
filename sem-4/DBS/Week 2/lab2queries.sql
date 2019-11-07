select name, dept_name from student2;

select ID, name from instructor where dept_name = 'Comp. Sci.';

select title from course where credits = 3 and dept_name = 'Comp. Sci.';

select takes.ID, takes. course_id, course.title from takes, course where takes.ID = 12345;

select name, salary from instructor where salary between 40000 and 90000;

update advisor set i_id = 10101 where s_id between 20000 and 40000;

update instructor set dept_name = 'Comp. Sci.' where dept_name = 'Finance';

update instructor set salary = 0.05 * salary + salary;

delete from department where dept_name = 'History';

delete from prereq where course_id = 'BIO-301';

delete from course where course_id NOT IN (select course_id from teaches);

alter table student2 add (DOB varchar(20));

alter table student2 modify (dept_name varchar(20));

alter table student2 drop column DOB;

select ID from instructor where ID not in (select ID from teaches);

select name, title, year from student2 natural join course natural join section where room_number = 101;

select student2.name, course_ID, course.title c_name from student2 natural join course natural join takes 
where year = 2009;

select name, salary inst_salary from instructor where salary > 
(select min(salary) from instructor
where dept_name = 'Comp. Sci.');

select name from instructor where dept_name like '%ch%';

select distinct prereq.course_id, course.title, prereq_id from prereq, course
where course.course_id = prereq.course_id
order by course_id, course.title DEsc, prereq_id;
