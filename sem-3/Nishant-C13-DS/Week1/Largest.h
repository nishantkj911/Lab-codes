int largest(int arr[],int len)
{
	int max = arr[0];
	for(int i=1; i<len; i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}

	return max;

}