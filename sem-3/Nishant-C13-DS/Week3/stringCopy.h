void copier(char str1[], char str2[], int index)
{
	str2[index] = str1[index];
	if(str1[index] == '\0')
	{
		return;
	}
	copier(str1, str2, index+1);
}