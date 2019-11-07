
import java.util.*;

class Student
{

    private int regNo;
    private String fullName;
    private GregorianCalendar DOJ;
    private short sem;
    private float GPA;
    private float CGPA;
    private int count = 0;

    private static Scanner input = new Scanner(System.in);

    Student(String n, GregorianCalendar d, short s, float g, float c)
    {
        fullName = n;
        DOJ = d;
        sem = s;
        GPA = g;
        CGPA = c;
        count++;

        regNo = ((DOJ.get(GregorianCalendar.YEAR) % 2000) * 100) + count;
    }

    Student()
    {
        this("", new GregorianCalendar(), (short) 0, 0.0f, 0.0f);
        regNo = ((DOJ.get(GregorianCalendar.YEAR) % 2000) * 100) + count;
    }

    void display()
    {
        System.out.println("Name: " + fullName + "\nRegNo: " + regNo);
        System.out.println("Date Of Joining: " + DOJ.get(Calendar.DAY_OF_MONTH) + "/" + (DOJ.get(Calendar.MONTH)+1)  + "/" + DOJ.get(Calendar.YEAR) + "\nSem: " + sem + "\nGPA: " + GPA);
    }

    static void changeName(Student[] a)
    {
        for (Student a1 : a)
        {
            String s1 = null;
            int n1 = a1.fullName.length();

            n1 = a1.fullName.lastIndexOf(" ", n1);
            s1 = a1.fullName.substring(n1 + 1);
            while (n1 > 0)
            {
                n1 = a1.fullName.lastIndexOf(" ", n1 - 1);
                s1 = a1.fullName.charAt(n1 + 1) + ". " + s1;
            }

            a1.fullName = s1;
            a1.display();
            System.out.println();
        }
    }

    static void studentStartsWithChar(char c, Student[] a)
    {
        for (Student a1 : a)
        {
            if (a1.fullName.charAt(0) == c)
            {
                a1.display();
                System.out.println();
            }
        }
    }

    static void studentContains(String sub, Student[] a)
    {
        for (Student a1 : a)
        {
            if (a1.fullName.indexOf(sub) >= 0)
            {
                System.out.println();
                a1.display();
                System.out.println();
            }
        }
    }

    static Student input()
    {
        System.out.println("name");
        String n = input.nextLine();
        
        System.out.println("date");
        int yr = input.nextInt();
        int mon = input.nextInt() - 1;
        int d = input.nextInt();
        GregorianCalendar j = new GregorianCalendar(yr, mon, d);
        System.out.println("sem");
        short s = input.nextShort();
        System.out.println("gpa");
        float g = input.nextFloat();
        System.out.println("cgpa");
        float c = input.nextFloat();
        input.nextLine();
        
        return new Student(n, j, s, g, c);
    }
}

class StudentTest
{

    static Scanner input = new Scanner(System.in);

    public static void main(String[] args)
    {
        System.out.println("Enter no. of students");
        int k = input.nextInt();
        Student[] arr = new Student[k];

        System.out.println("Enter Name, Date(yyyy/mm/dd), semester, GPA and CGPA resp. ");
        for (int i = 0; i < k; i++)
        {
            System.out.println("For Student " + (i + 1));
            arr[i] = Student.input();
        }
        
        for(Student a1: arr)
        {
            a1.display();
            System.out.println();
        }

        System.out.println("1. Sort wrt sem and GPA\n2. Sort wrt name\n3. List all students starting with a char\n4. List all students containing substring\n5. Change name to initials\n");
        while (true)
        {
            switch (input.nextInt())
            {
                case 1:
                    return;
                case 2:
                    return;
                case 3:
                    System.out.print("Enter the character: ");
                    Student.studentStartsWithChar(input.next().charAt(0), arr);
                    return;
                case 4:
                    System.out.print("Enter the substring: ");
                    Student.studentContains(input.next(), arr);
                    return;
                case 5:
                    System.out.println("Enter the name of the student to change name");
                    Student.changeName(arr);
                    return;
                default:
                    System.out.println("Please enter valid choice");
            }
        }
    }
}
