#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct{
	int arr[SIZE];
	int front1, rear1, cap1;
	int front2, rear2, cap2;
} dcq;

typedef dcq * dcq_p;

int isFullQueue (dcq queue, int qno) {
	if (qno == 1 && queue.cap1 == SIZE/2)
		return 1;
	else if (qno == 2 && queue.cap2 == SIZE/2)
		return 1;
	return 0;
}

int isEmptyQueue (dcq queue, int qno) {
	if (qno == 1 && queue.cap1 == 0)
		return 1;
	else if (qno == 2 && queue.cap2 == 0)
		return 1;
	return 0;
}

int dcqenqueue (dcq_p queue, int item, int qno) {
	if (isFullQueue(*queue, qno)) {
		printf("\n\t\tQUEUE '%d' OVERFLOW!\n\n", qno);
		return 0;
	}
	
	if (qno == 1) 
	{
	
		if (isEmptyQueue(*queue, qno)) 
			queue->front1 = queue->rear1 = 0;

		else if (queue->rear1 == SIZE/2 - 1)
			queue->rear1 = 0;
			
		else
			queue->rear1 += 1;
			
		*(queue->arr + queue->rear1) = item;
		queue->cap1++;
		return 1;
	}
	
	if (qno == 2) 
	{
		if (isEmptyQueue(*queue, qno))
			queue->front2 = queue->rear2 = SIZE - 1;
			
		else if (queue->rear2 == SIZE/2)
			queue->rear2 = SIZE - 1;
			
		else
			queue->rear2 -= 1;
			
		*(queue->arr + queue->rear2) = item;
		queue->cap2++;
		return 1;
	}
}

int dcqdequeue 	 (dcq_p queue, int qno) {
	if (isEmptyQueue(*queue, qno)) {
		printf("\n\t\tQUEUE '%d' UNDERFLOW!\n\n", qno);
		return -1;
	}
	
	int item = 0;
	if (qno == 1) {
	
		item = *(queue->arr + queue->front1);
		*(queue->arr + queue->front1) = 0;
		
		if (queue->front1 == queue->rear1)
			queue->front1 = queue->rear1 = -1;
			
		else if (queue->front1 == SIZE/2 - 1)
			queue->front1 = 0;
			
		else
			queue->front1 += 1;
			
		queue->cap1--;
	}
	
	if (qno == 2) {
	
		item = *(queue->arr + queue->front2);
		*(queue->arr + queue->front2) = 0;
		
		if (queue->front2 == queue->rear2)
			queue->front2 = queue->rear2 = SIZE - 1;
			
		else if (queue->front2 == SIZE/2)
			queue->front2 = SIZE - 1;
			
		else
			queue->front2 -= 1;
			
		queue->cap2--;
	}
	return item;
}

void dcqdisplay (dcq queue, int qno) {
	if (isEmptyQueue(queue, qno)) {
		printf("\n\t\tEMPTY QUEUE %d.\n\n", qno);
		return;
	}
	
	printf("\n\tQUEUE '%d': ", qno);
	int i;
	
	if (qno == 1) {
		if (queue.rear1 >= queue.front1)
			for (i = queue.front1; i <= queue.rear1; ++i)
				printf("\t%d", *(queue.arr + i));
				
		else {
			for (i = queue.front1; i < SIZE/2; ++i)
				printf("\t%d", *(queue.arr + i));
			for (i = 0; i <= queue.rear1; ++i)
				printf("\t%d", *(queue.arr + i));
		}		
	}
	
	else if (qno == 2) {
		if (queue.rear2 <= queue.front2)
			for (i = queue.front2; i >= queue.rear2; --i)
				printf("\t%d", *(queue.arr + i));
				
		else {
			for (i = queue.front2; i >= SIZE/2; --i)
				printf("\t%d", *(queue.arr + i));
			for (i = SIZE - 1; i >= queue.rear2; --i)
				printf("\t%d", *(queue.arr + i));
		}
	}
	
	printf ("\n\n");
}

