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
void Push(int item)
{
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
	printf("\nInsert element in the Stack\n");
}
void Pop()
{
	NODE *p;
	if(start==NULL)
	{
		return;
	}
	else
	{
		p=start;
		start=start->next;
		printf("\nDeleted element is:%d\n",p->data);
		free(p);
	}
	printf("\nDeleted the element\n");
}
void Toppoint()
{
	NODE *curr;
	int count=1;
	curr=start;
	if(curr==NULL)
	{
		printf("\nStack is empty\n");
	}
	while(curr!=NULL)
	{
		printf("\ndata %d:%d",count,curr->data);
		curr=curr->next;
		count++;
	}
}
int main()
{
	int choice,item;
	do
	{
		printf("\n1. Insert element in the stack...\n");
		printf("\n2. Delete element in the stack...\n");
		printf("\n3. Display the element...\n");
		printf("\n4. Enter the exit...\n");
		printf("\nenter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nenter the element:");
				scanf("%d",&item);
				Push(item);
				break;
			case 2:
				Pop();
				break;
			case 3:
				Toppoint();
				break;
			case 4:
				exit(0);
			default:printf("\nWrong Choice...\n");
		}
	}
	while(choice!=4);
}
