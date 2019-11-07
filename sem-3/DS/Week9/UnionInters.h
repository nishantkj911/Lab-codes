#include "scll.h"

scll* inter(scll* entry1, scll* entry2)
{
	scll* temp = entry1, *temp2 = entry2;
	scll* inter = NULL;

	do
	{
		do
		{
			if(temp->data == temp2->data)
			{
				inter = addel(inter, temp->data);
			}

			temp = temp->link;

		}while(temp->data != entry1->data);

		temp2 = temp2->link;

	}while(temp2->data != entry2->data);

	return inter;
}

scll* unionll(scll* entry1, scll* entry2)
{
	scll* in = inter(entry1, entry2), * temp = entry1;
	scll* un = NULL;

	if(in == NULL)
	{
		//printf("\nIn case of null intersection\n\n");

		temp = entry2;
		do
		{
			un = addel(un, temp->data);
			temp = temp->link;
		}while(temp->data != entry2->data);

		temp = entry1;
		do
		{
			un = addel(un, temp->data);
			temp = temp->link;
		}while(temp->data != entry1->data);

		return un;
	}

	do
	{
		scll* temp2 = in;
		int flag = 0;
		do
		{
			if(temp->data == temp2->data)
			{
				// printf("element %d being checked against %d\n", temp->data, temp2->data);
				flag = 1;
			}

			temp2 = temp2->link;
		}while(temp2->data != in->data);

		if(flag == 1) {
			temp = temp->link;
			continue;
		}

		un = addel(un, temp->data);

		temp = temp->link;
	}while(temp->data != entry1->data);

	temp = entry2;
	do
	{
		un = addel(un, temp->data);
		temp = temp->link;
	}while(temp->data != entry2->data);

	// printf("Union Ended\n");

	return un;
}