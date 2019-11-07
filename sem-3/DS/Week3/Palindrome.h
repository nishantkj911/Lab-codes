int isPalindrome(char* inputString, int leftIndex, int rightIndex)
{
	if(leftIndex >= rightIndex)
		return 1;
	if(inputString[leftIndex] == inputString[rightIndex])
	{
		return isPalindrome(inputString, leftIndex+1, rightIndex-1);
	}
	return 0;
}