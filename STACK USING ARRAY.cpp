#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max];
int top=-1;
void Push();
void Pop();
void Toppoint();
int main()
{
	int choice;
	do
	{
		printf("\n1. Insert the element in the stack\n");
		printf("\n2. Delete the element in the stack\n");
		printf("\n3. Display the element entire the stack\n");
		printf("\n4. Quit\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				Push();
				break;
			case 2:
				Pop();
				break;
			case 3:
				Toppoint();
				break;
			case 4:
				exit(0);
			default:printf("\nWrong Choice\n");
		}
	}
	while(choice!=4);
}
void Push()
{
	int add_item;
	if(top==max-1)
	{
		printf("\nStack is full\n");
	}
	else
	{
		printf("\nEnter the element in the stack:");
		scanf("%d",&add_item);
		top=top+1;
		stack[top]=add_item;
	}
}
void Pop()
{
	int item;
	if(top==-1)
	{
		printf("\nStack is empty\n");
	}
	else
	{
		item=stack[top];
		top=top-1;
		printf("\nDeleted element in the entire list\n");
		printf("Data:%d",item);
	}
}
void Toppoint()
{
	int i,count=1;
	if(top==-1)
	{
		printf("\nStack is empty\n");
	}
	else
	{
		printf("\nDisplay the element for entire list\n");
		for(i=top;i>=0;i--)
		{
			printf("data %d:%d",count,stack[i]);
			printf("\n");
			count++;
		}
	}
}
