import buildings.*;
import java.util.Scanner;

public class BuildingTest
{
	private static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args)
	{
		Building underC = new Building();
		House apar = new House();
		School sc = new School();
		
		System.out.println("For the Building...");
		System.out.print("Square Footage: ");
		underC.setSqFoot(input.nextInt());
		System.out.print("No. of Stories: ");
		underC.setStories(input.nextInt());

		System.out.println("For the House...");
		System.out.print("Square Footage: ");
		apar.setSqFoot(input.nextInt());
		System.out.print("No. of Stories: ");
		apar.setStories(input.nextInt());
		System.out.print("No of Bedrooms: ");
		apar.setNoOfBedrooms(input.nextInt());
		System.out.print("No of Bathrooms: ");
		apar.setNoOfBathrooms(input.nextInt());

		System.out.println("For the School...");
		System.out.print("Square Footage: ");
		sc.setSqFoot(input.nextInt());
		System.out.print("No. of Stories: ");
		sc.setStories(input.nextInt());
		System.out.print("No. of Classrooms: ");
		sc.setNoOfClassrooms(input.nextInt());
		System.out.print("Grade: ");
		sc.setGrade(input.next());
		
		System.out.println("For the building: \n" + underC);
		System.out.println("For the house: \n" + apar);
		System.out.println("For the school: \n" + sc);
		
	}

}
