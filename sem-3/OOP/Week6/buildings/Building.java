package p1;

class Building
{
	private int sqFoot;
	private int stories;

	public int getSqFoot()
	{
		return sqFoot;
	}

	public void setSqFoot(int sqFoot)
	{
		this.sqFoot = sqFoot;
	}

	public int getStories()
	{
		return stories;
	}

	public void setStories(int stories)
	{
		this.stories = stories;
	}

	@Override
	public String toString()
	{
		return "Square Footage: " + this.getSqFoot() + "\nNo. of floors: " + this.getStories();
	}

	
}

class House extends Building
{
	private int noOfBedrooms;
	private int noOfBathrooms;

	public int getNoOfBedrooms()
	{
		return noOfBedrooms;
	}

	public void setNoOfBedrooms(int noOfBedrooms)
	{
		this.noOfBedrooms = noOfBedrooms;
	}

	public int getNoOfBathrooms()
	{
		return noOfBathrooms;
	}

	public void setNoOfBathrooms(int noOfBathrooms)
	{
		this.noOfBathrooms = noOfBathrooms;
	}

	@Override
	public String toString()
	{
		// TODO Auto-generated method stub
		return super.toString() + "\nNo. of Bedrooms: " + this.getNoOfBedrooms() + "\nNo. of Bathrooms: " + this.getNoOfBathrooms();
	}
	
}

class School extends Building
{
	private int noOfClassrooms;
	private String grade;

	public int getNoOfClassrooms()
	{
		return noOfClassrooms;
	}

	public void setNoOfClassrooms(int noOfClassrooms)
	{
		this.noOfClassrooms = noOfClassrooms;
	}

	public String getGrade()
	{
		return grade;
	}

	public void setGrade(String grade)
	{
		this.grade = grade;
	}

	@Override
	public String toString()
	{
		// TODO Auto-generated method stub
		return super.toString() + "\nNo of Classrooms: " + this.getNoOfClassrooms() + "\nGrade: " + this.getGrade();
	}
	
	
}
