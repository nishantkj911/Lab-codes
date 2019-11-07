#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
//#include <mpich/mpi.h>
#include <string.h>

char toggleCase(char a)
{
	if (a >= 'a' && a <= 'z')
		a -= 32;
	else if (a >= 'A' && a <= 'Z')
		a += 32;

	return a;
}

int main(int argc, char *argv[])
{
	// program doesn't work for sender != 0
	/* try taking input in root and then sending to one process 
	and then carrying out the communication */
	int rank, size, tag = 0, reciever = 3, sender = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if (rank == sender)
	{
		char *buf = calloc(BUFSIZ, sizeof(char));
		printf("Enter the message\n");
		scanf("%[^\n]%*c", buf);
		int len = strlen(buf);
		len++;

		MPI_Ssend(&len, 1, MPI_INT, reciever, tag++, MPI_COMM_WORLD);
		printf("Length sent successfully\n");
		MPI_Ssend(buf, len, MPI_CHAR, reciever, tag++, MPI_COMM_WORLD);
		printf("Message sent successfully\n");
		MPI_Recv(buf, len, MPI_CHAR, reciever, tag++, MPI_COMM_WORLD, &status);
		printf("The recieved message after modification is: %s\n", buf);
	}
	else if (rank == reciever)
	{
		int len;
		MPI_Recv(&len, 1, MPI_INT, sender, tag++, MPI_COMM_WORLD, &status);
		printf("Length recieved successfully\n");

		char *buf = calloc(len, sizeof(char));
		MPI_Recv(buf, len, MPI_CHAR, sender, tag++, MPI_COMM_WORLD, &status);
		printf("Original message recieved is %s\n", buf);

		for (int i = 0; i < len; i++)
		{
			buf[i] = toggleCase(buf[i]);
		}

		MPI_Ssend(buf, len, MPI_CHAR, sender, tag++, MPI_COMM_WORLD);
		printf("Modified message sent successfully\n");
	}
	else
	{
		printf("Me, rank %i processor is sitting idle\n", rank);
	}
	MPI_Finalize();
	return 0;
}