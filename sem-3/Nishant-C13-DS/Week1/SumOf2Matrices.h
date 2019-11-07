void sumOfMatrix(int a[][100], int b[][100],int r,int c, int outputMatrix[][100])
{
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			outputMatrix[i][j] = a[i][j] + b[i][j];
		}
	}
}
