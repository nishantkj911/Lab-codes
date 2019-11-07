#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char dirname[10];
	DIR* p;
	struct dirent* d;

	printf("Enter the directory name\n");
	scanf("%s", dirname);

	p = opendir(dirname);

	if(p == NULL)
	{
		printf("Cannot find directory\n");
		exit(-1);
	}

	while(d = readdir(p))
	{
		printf("%s\n", d->d_name);
	}
	return 0;

}