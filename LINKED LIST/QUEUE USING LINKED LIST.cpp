#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *start;
void Enqueue(int item)
{
	int data;
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	p->data=item;
	if(start==NULL)
	{
		p->next=NULL;
	}
	else
	{
		p->next=start;
	}
	start=p;
	printf("\nInsert the element in the Queue\n");
}
void Dequeue()
{
	NODE *loc,*p;
	if(start==NULL)
	{
		printf("\nQueue is empty\n");
	}
	else if(start->next==NULL)
	{
		p=start;
		start=NULL;
		printf("\nDeleted element is:%d\n",p->data);
		free(p);
	}
	else
	{
		loc=start;
		p=start->next;
		while(p->next!=NULL)
		{
			loc=p;
			p=p->next;
		}
		loc->next=NULL;
		printf("\nDeleted element is:%d\n",p->data);
		free(p);
	}
	printf("\nDelete the queue element\n");
}
void Peep()
{
	NODE *curr=start;
	int count=1;
	if(start==NULL)
	{
		printf("\nQueue is empty\n");
	}
	while(curr!=NULL)
	{
		printf("data is %d:%d\n",count,curr->data);
		curr=curr->next;
		count++;
	}
}
int main()
{
	int choice,item;
	do
	{
		printf("\n1. Choose for insert the element in queue...\n");
		printf("\n2. Choose for delete the element in queue...\n");
		printf("\n3. Choose for display the element in queue...\n");
		printf("\n4. Choose for quit\n");
		printf("\nEnter the choice the value:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element:");
				scanf("%d",&item);
				Enqueue(item);
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				Peep();
				break;
			case 4:
				exit(0);
			default:printf("\nWrong Choice...\n");
		}
	}
	while(choice!=4);
}
