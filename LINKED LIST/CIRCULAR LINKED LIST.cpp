#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *start,*last;
void createcircularlist(int item)
{
	NODE *ptr;
	ptr=(NODE *)malloc(sizeof(NODE));
	ptr->data=item;
	ptr->next=ptr;
	start=ptr;
	last=ptr;
}
void createbegin(int item)
{
	NODE *ptr;
	ptr=(NODE *)malloc(sizeof(NODE));
	ptr->data=item;
	if(start==NULL)
	{
		ptr->next=ptr;
		start=ptr;
	    last=ptr;
	}
	else
	{
		ptr->next=start;
		start=ptr;
		last->next=ptr;
	}
}
void createend(int item)
{
	NODE *ptr;
	ptr=(NODE *)malloc(sizeof(NODE));
	ptr->data=item;
	if(start==NULL)
	{
		ptr->next=ptr;
		start=ptr;
		last=ptr;
	}
	else
	{
		last->next=ptr;
		last=ptr;
		last->next=start;
	}
}
void deletebegin()
{
	NODE *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("\ncircular linked list is empty\n");
	}
	else
	{
		ptr=start;
		start=start->next;
		printf("\ndeleted node is:%d",ptr->data);
		free(ptr);
		last->next=start;
	}
}
void deleteend()
{
	NODE *ptr,*q;
	ptr=start;
	if(ptr==NULL)
	{
		printf("\ncircular linked list is empty\n");
	}
	else
	{
		while(ptr->next!=last)
		{
			NODE *q;
			q=ptr;
			ptr=ptr->next;
		}
		printf("\ndeleted node is:%d",ptr->data);
		free(ptr);
		last->next=start;
		last=q;
	}
}
void display()
{
	NODE *curr;
	curr=start;
	if(curr==NULL)
	{
		printf("\ncircular linked list is empty\n");
	}
	else
	{
		while(curr->next!=start)
	   {
			printf("\ndisplay:%d",curr->data);
			curr=curr->next;
	   }
	}
}
int main()
{
	int choiche,item;
	do
	{
		printf("\n1. insert node\n");
		printf("\n2. insert node at the begin\n");
		printf("\n3. insert node at the end\n");
		printf("\n4. delete node from the begin\n");
		printf("\n5. delete node from the end\n");
		printf("\n6. display the node\n");
		printf("\n7. exit\n");
		printf("\nenter your choiche:");
		scanf("%d",&choiche);
		switch(choiche)
		{
			case 1:
				printf("enter the node:");
				scanf("%d",&item);
				createcircularlist(item);
				break;
			case 2:
				printf("enter the node:");
				scanf("%d",&item);
				createbegin(item);
				break;
			case 3:
				printf("enter the node:");
				scanf("%d",&item);
				createend(item);
				break;
			case 4:
				deletebegin();
				break;
			case 5:
				deleteend();
				break;
			case 6:
				display();
				break;
			case 7:
				exit(0);
				break;
			default:printf("\nwrong choiche\n");
		}
	}
	while(choiche!=7);
}
