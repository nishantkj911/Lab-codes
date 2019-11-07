int linSearch(int arr[], int len, int search)
{
	for(int i = 0; i<len; i++)
	{
		if(search == arr[i])
			return 1;
	}

	return 0;
}