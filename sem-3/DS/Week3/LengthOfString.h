int strlength(char* str, int index)
{
	if(str[index] == '\0')
	{
		return 0;
	}

	return (1 + strlength(str, index + 1));
}

/*
or

int soiaf(char* str)
{
	static int length = 0;
	if(*str != '\0')
	{
		length++;
		soiaf(++str);
	}

	return length;
}
*/