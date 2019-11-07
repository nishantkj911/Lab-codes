package p1;
import java.util.*;

class Patient
{
	protected String name;
	protected int age;
	protected int hosNo;

	Patient(String n, int a, int h)
	{
		name = n;
		age = a;
		hosNo = h;
	}

	Patient()
	{
		this("", 0, 0000);
	}

	@Override
	public String toString()
	{
		return "\nName: " + name + "\nAge: " + age + "\nHospital No.: " + hosNo;
	}
}

class Billing extends Inpatient
{
	protected GregorianCalendar disDate;

	Billing(String n, int a, int h, String d, GregorianCalendar ad, String r, GregorianCalendar dd)
	{
		super(n, a, h, d, ad, r);
		disDate = dd;
	}

	Billing()
	{
		this("", 0, 0000, "", new GregorianCalendar(), "", new GregorianCalendar());
	}

	void setDD(GregorianCalendar d)
	{
		disDate = d;
	}

	void calcAmt()
	{
		long days = (disDate.getTimeInMillis() - admDate.getTimeInMillis()) / 1000 / 3600 / 24;
		int amt = 0;
		if (days < 0)
		{
			System.out.println("Invalid discharge date");
			return;
		}

		switch (roomType)
		{
			case "Special":
				amt = (1000 * (int) days) + (200 * (int) days);
				break;
			case "SemiSpecial":
				amt = (500 * (int) days) + (100 * (int) days);
				break;
			case "General":
				amt = (100 * (int) days) + (50 * (int) days);
				break;
			default:
				System.out.println("Invalid Room Type");
				return;
		}

		System.out.println("The amount to be paid is " + amt);
		return;
	}

	@Override
	public String toString()
	{
		String s = disDate.get(Calendar.DAY_OF_MONTH) + "/" + (disDate.get(Calendar.MONTH) + 1)
				+ "/" + disDate.get(Calendar.YEAR);
		// TODO Auto-generated method stub
		return super.toString() + "\nDate of Discharge: " + s;
	}

}


class Inpatient extends Patient
{
	protected String deptName;
	protected GregorianCalendar admDate;
	protected String roomType;

	Inpatient(String n, int a, int h, String d, GregorianCalendar ad, String r)
	{
		super(n, a, h);
		deptName = d;
		admDate = ad;
		roomType = r;
	}

	Inpatient()
	{
		this("", 0, 0000, "", new GregorianCalendar(), "");
	}

	@Override
	public String toString()
	{
		String s = admDate.get(Calendar.DAY_OF_MONTH) + "/" + (admDate.get(Calendar.MONTH) + 1) + "/"
				+ admDate.get(Calendar.YEAR);
		return "\nName: " + name + "\nAge: " + age + "\nHospital No.: " + hosNo + "\nDept. Name: " + deptName
				+ "\nDate Of Admission: " + s +"\nRoom Type: " + roomType;
	}

}

class PatientTest
{
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args)
	{
		System.out.println(
				"Enter the details: (Name, Age, Hos. No., Dept. Name, Adm. date, roomType and discharge date) ");
		String n, d, r;
		int a, h;
		GregorianCalendar ad, dd;

		n = input.nextLine();
		a = input.nextInt();
		h = input.nextInt();
		input.nextLine();
		d = input.next();
		ad = new GregorianCalendar(input.nextInt(), input.nextInt() - 1, input.nextInt());
		input.nextLine();
		r = input.next();
		dd = new GregorianCalendar(input.nextInt(), input.nextInt() - 1, input.nextInt());

		Billing p1 = new Billing(n, a, h, d, ad, r, dd);
		
		System.out.println();
		System.out.println(p1);

		p1.calcAmt();
	}
}
