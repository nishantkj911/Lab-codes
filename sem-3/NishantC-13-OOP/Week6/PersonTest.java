package p1;
import java.util.*;

class Person
{
	private String name;
	private GregorianCalendar DOB;

	Person(String n, GregorianCalendar d)
	{
		name = n;
		DOB = d;
	}

	Person()
	{
		this("", new GregorianCalendar());
	}

	// accessor methods
	String getName()
	{
		return this.name;
	}

	GregorianCalendar getDOB()
	{
		return DOB;
	}

	@Override
	public String toString()
	{
		return "The person's Details: \nName: " + this.getName() + "\nDOB: " + this.getDOB().get(Calendar.DAY_OF_MONTH)
				+ "/" + (this.getDOB().get(Calendar.MONTH) + 1) + "/" + this.getDOB().get(Calendar.YEAR);
	}
}

class CollegeGraduate extends Person
{
	private double GPA;
	private int gradYear;

	CollegeGraduate(String n, GregorianCalendar d, double g, int y)
	{
		super(n, d);
		GPA = g;
		gradYear = y;
	}

	CollegeGraduate()
	{
		this("", new GregorianCalendar(), 0.0d, 0);
	}

	double getGPA()
	{
		return GPA;
	}

	int getGradYear()
	{
		return gradYear;
	}

	@Override
	public String toString()
	{
		return "Name: " + this.getName() + "\nDOB: " + this.getDOB().get(Calendar.DAY_OF_MONTH) + "/"
				+ (this.getDOB().get(Calendar.MONTH) + 1) + "/" + this.getDOB().get(Calendar.YEAR) + "\nGPA: "
				+ this.getGPA() + "\nYear Of Graduation: " + this.getGradYear();
	}
}

class PersonTest
{
	private static Scanner input = new Scanner(System.in);

	public static void main(String[] args)
	{
		System.out.println("Enter the name and Date Of Birth(yyyy/mm/dd) of the person");
		Person p1 = new Person(input.nextLine(),
				new GregorianCalendar(input.nextInt(), input.nextInt() - 1, input.nextInt()));

		System.out.println(p1);
		
		input.nextLine();
		System.out.println("Enter the name, Date Of Birth(yyyy/mm/dd), GPA and year of grad of the college graduate");
		CollegeGraduate cg1 = new CollegeGraduate(input.nextLine(),
				new GregorianCalendar(input.nextInt(), input.nextInt() - 1, input.nextInt()), input.nextDouble(),
				input.nextInt());

		System.out.println("The college graduate's Details: ");
		System.out.println("Name: " + cg1.getName() + "\nDOB: " + cg1.getDOB().get(Calendar.DAY_OF_MONTH) + "/"
				+ (cg1.getDOB().get(Calendar.MONTH) + 1) + "/" + cg1.getDOB().get(Calendar.YEAR) + "\nGPA: "
				+ cg1.getGPA() + "\nYear Of Graduation: " + cg1.getGradYear());
	}
}
