#include<stdio.h>
#define N 5
int Q[20],front=-1,rear=-1;
void enCQ(int item)
	{
	if (front==-1)
		{
		front=rear=0;
		Q[rear]=item;
		}
	else if ((rear+1)%N!=front)
		{
		rear=(rear+1)%N;
		Q[rear]=item;
		}
	else
		printf("Queue is full\n");
	}
void deCQ()
	{
	if (front==-1)
		printf("Empty queue\n");
	else
		{
		printf("The deleted element is %d",Q[front]);\
		if (front==rear)
			front=rear=-1;
		else
			front=(front+1)%N;
		}
	}
void dispQueue()
	{
	if (front==-1)
		printf("Empty queue\n");
	else
		{
		int i=front;
		while(i!=rear)
			{
			printf("%d\t",Q[i]);
			i=(i+1)%N;
			}
		printf("%d\n",Q[rear]);
		}
	}
void main()
	{
	int o=0,e;
	while(o!=4)
		{
		printf("MENU\n1.Enqueue\t2.Dequeue\t3.Display Queue\t4.Exit\n");
		scanf("%d",&o);
		switch(o)
			{
			case 1:
				printf("Enter the number to be queued: ");
				scanf("%d",&e);
				enCQ(e);
				break;
			case 2:
				deCQ();
				break;
			case 3:
				dispQueue();
				break;
			case 4:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid input\n");
			}
		}
	}
	
