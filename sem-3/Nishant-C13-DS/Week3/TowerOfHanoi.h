int tower(int n, char source, char temp, char dest)
{
	static int moves = 0;
	if(n==1)
	{
		printf("Move 1 disk from %c to %c\n", source, dest);
		return moves + 1;
	}

	//moving n-1 form source(a) to dest(b) using temp(c)
	moves = tower(n-1, source, dest, temp);

	moves++;
	printf("move %i disks from %c to %c using %c as aux", n, source, dest, temp);

	//moving n-1 diskd from b to c using a as aux
	moves = tower(n-1, temp, source, dest);

	//count the no. of moves

	return moves;
}