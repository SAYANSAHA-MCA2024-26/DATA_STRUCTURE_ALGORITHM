#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int rear=-1;
int front=-1;
void Enqueue();
void Dequeue();
void Peep();
int main()
{
	int choice;
	while(1)
	{
		printf("\n1. Insert the element in queue\n");
		printf("\n2. Delete the element in queue\n");
		printf("\n3. Display the element\n");
		printf("\n4. Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				Enqueue();
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				Peep();
				break;
			case 4:
				exit(0);
			default:printf("\nwrong choice...\n");
		}
	}
}
void Enqueue()
{
	int add_item;
	if(rear==max-1)
	{
		printf("\nQueue is Overflow\n");
	}
	else
	{
		if(front==-1 && rear==-1)
		{
			front=0;
		}
		printf("\nEntre the element insert in queue:");
		scanf("%d",&add_item);
		rear=rear+1;
		queue[rear]=add_item;
	}
}
void Dequeue()
{
	int data;
	if(front==-1||front>rear)
	{
		printf("\nQueue is Underflow\n");
		front=-1;
		rear=-1;
	}
	else
	{
		data=queue[data];
		printf("\nDeleted element is:%d",data);
		front=front+1;
	}
}
void Peep()
{
	int i;
	if(front==-1)
	{
		printf("\nQueue is Empty\n");
	}
	else
	{
		printf("\nEntire Queue is:\n");
		for(i=front;i<=rear;i++)
		{
			printf("data [%d]:%d\n",i,queue[i]);
		}
		printf("\n");
	}
}
