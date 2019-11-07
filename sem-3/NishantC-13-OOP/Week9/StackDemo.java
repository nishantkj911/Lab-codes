import java.util.*;

interface IGen <T>
{
	void push(T i);
	void pop();
}

class Gen<T> implements IGen <T>
{
	int tos;
	T arr[];
	
	Gen(T[] ref)
	{
		arr = ref;
		tos = -1;
	}
	
	public void push(T i)
	{
		if(tos == arr.length - 1)
		{
			System.out.println("Stack Overflow!!");
			return;
		}
		
		arr[++tos] = i;
	}
	
	public void pop()
	{
		if(tos == -1)
		{
			System.out.println("Stack Underflow");
			return;
		}
		
		tos--;
		
	}
	
	@Override
	public String toString()
	{
		System.out.println("Elements are: ");
		String str = "";
		for(int i = tos; i>=0; i--)
			str+=arr[i];
			
		return str;
	}
	
}

class Student
{
	String name;
	int regNo;
	int sem;
	
	Student (String name, int reg, int sem)
	{
		this.name = name;
		regNo = reg;
		this.sem = sem;
	}
	
	@Override
	public String toString()
	{
		return "Name: " + name + "\nReg No: " + regNo + "\nSemester: " + sem + "\n\n";
	}
	
}

class Employee
{
	String name;
	String dept;
	
	
	Employee (String name, String dept)
	{
		this.name = name;
		this.dept = dept;
	}
	
	@Override
	public String toString()
	{
		return "Name: " + name + "\nDepartment: " + dept + "\n\n";
	}
	
}

class StackDemo
{
	public static void main(String[] args)
	{
		Student s1 = new Student("Nishant KJ", 160905074, 3);
		Student s2 = new Student("Rohith M", 160764331, 7);
		Student s3 = new Student("David M", 165456431, 5);
		
		Student[] stArr = new Student[10];
		
		Gen<Student> a = new Gen<>(stArr);
		a.push(s1);
		a.push(s2);
		a.push(s3);
		System.out.println(a);
		
		a.pop();
		System.out.println(a);
		
		//Now Employee
		
		Employee e1 = new Employee("Ashish P", "HR");
		Employee e2 = new Employee("Frank S", "Management");
		Employee e3 = new Employee("David Q", "Design");
		
		Employee[] eArr = new Employee[10];
		
		Gen<Employee> b = new Gen<>(eArr);
		b.push(e1);
		b.push(e2);
		b.push(e3);
		System.out.println(b);
		
		b.pop();
		System.out.println(b);
		
	}
}
