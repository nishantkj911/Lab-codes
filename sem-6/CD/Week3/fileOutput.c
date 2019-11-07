// #include <stdio.h>
// #include <stdlib.h>

#define YOLO 1029

int main(int argc, char const *argv[])
{
	write("Hello, # world\n");
	int n[10];
	read("%i %i", &n[1], &n[4]);
	char c;
	for (int i = 0; i < 10; i++)
	{
		n[i] = i + 3;
		write("\n");
		if (i == 4)
			break;
	}
	return 0;
}