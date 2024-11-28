#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node NODE;
NODE *start,*last;
void createlist(int item)
{
	NODE *ptr;
	ptr=(NODE *)malloc(sizeof(NODE));
	ptr->data=item;
	ptr->next=NULL;
	ptr->prev=NULL;
	start=ptr;
	last=ptr;
}
void insertbegin(int item)
{
	NODE *ptr;
	ptr=(NODE *)malloc(sizeof(NODE));
	ptr->data=item;
	if(start==(NODE *)NULL)
	{
		ptr->prev=ptr->next=(NODE *)NULL;
		last=start=ptr;
	}
	else
	{
		ptr->prev=NULL;
		ptr->next=start;
		start->prev=ptr;
		start=ptr;
	}
	printf("\nInsert begining element in the Double linked list\n");
}
void insertend(int item)
{
	NODE *ptr;
	ptr=(NODE *)malloc(sizeof(NODE));
	ptr->data=item;
	if(last==(NODE *)NULL)
	{
		ptr->prev=ptr->next=NULL;
		last=start=ptr;
	}
	else
	{
		ptr->next=NULL;
		ptr->prev=last;
		last->next=ptr;
		last=ptr;
	}
	printf("\nInsert end element in the Double linked list\n");
}
void insertbefore(int item)
{
	NODE *ptr,*temp1,*temp2;
	int key;
	printf("\nEnter element before insert any node value:");
	scanf("%d",&key);
	if(start==NULL)
	{
		printf("\nDoubly linked list is empty\n");
	}
	else
	{
		ptr=(NODE *)malloc(sizeof(NODE));
		ptr->prev=NULL;
		ptr->data=item;
		ptr->next=NULL;
		temp1=start;
		temp2=start;
		while(temp1->data!=key)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		temp2->next=ptr;
		ptr->prev=temp2;
		ptr->next=temp1;
		temp1->prev=ptr;
	}
	printf("\nInsert element before the any node value in the Double linked list\n");
}
void insertafter(int item)
{
	NODE *temp1,*ptr,*temp2;
	int key;
	printf("\nEnter element after insert any node value:");
	scanf("%d",&key);
	if(start==NULL)
	{
		printf("\nDoubly linked list is empty\n");
	}
	else
	{
		ptr=(NODE *)malloc(sizeof(NODE));
		ptr->prev=NULL;
		ptr->data=item;
		ptr->next=NULL;
		temp1=start;
		while(temp1->data!=key)
		{
			temp1=temp1->next;
		}
		temp2=temp1->next;
		temp1->next=ptr;
		ptr->prev=temp1;
		temp2->prev=ptr;
		ptr->next=temp2;
	}
}
void deletebegin()
{
	NODE *ptr;
	if(start==NULL)
	{
		return;
	}
	else if(start->next==NULL)
	{
		ptr=start;
		last=start=NULL;
	}
	else
	{
		ptr=start;
		start=start->next;
		start->prev=NULL;
	}
	printf("deleted element is:%d",ptr->data);
	free(ptr);
	printf("\nDelete begining element in the Double linked list\n");
}
void deleteend()
{
	NODE *ptr;
	if(start==NULL)
	{
		return;
	}
	else if(start->next==NULL)
	{
		ptr=start;
		last=start=NULL;
	}
	else
	{
		ptr=start;
		last=last->prev;
		last->next=NULL;
	}
	printf("deleted element is:%d",ptr->data);
	free(ptr);
	printf("\nDelete end element in the Double linked list\n");
}
void deleteafter()
{
	NODE *curr=start,*ptr;
	int key;
	printf("\nDelete element after any node value:");
	scanf("%d",&key);
	if(start==NULL)
	{
		printf("\nDoubly linked list is empty\n");
	}
	else
	{
		while(curr->data!=key)
		{
			curr=curr->next;
		}
		ptr=curr->next;
		curr->next=NULL;
		last=curr;
		printf("\nDeleted element is after node:%d",ptr->data);
		free(ptr);
	}
	printf("\nDelete element after the given node\n");
}
void deleteentirelist()
{
	NODE *temp;
	while(temp!=NULL)
	{
		temp=start;
		start=start->next;
		free(temp);
    }
    return NULL;
}
void display()
{
	NODE *curr=start;
	int count=1;
	if(curr==NULL)
	{
		printf("\nDouble linked list is empty\n");
	}
	while(curr!=NULL)
	{
		printf("data %d:%d\n",count,curr->data);
		curr=curr->next;
		count++;
	}
}
int main()
{
	int choice,item;
	do
	{
		printf("\n1. Create doubly linked list\n");
		printf("\n2. Insert element at the begin\n");
		printf("\n3. Insert element at the end\n");
		printf("\n4. Insert element before the any node\n");
		printf("\n5. Insert element after the any node\n");
		printf("\n6. Delete element at the begin\n");
		printf("\n7. Delete element at the end\n");
		printf("\n8. Delete element after the node\n");
		printf("\n9. Delete element entire the node\n");
		printf("\n10. Display element entire the doubly linked list\n");
		printf("\n11.Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element:");
				scanf("%d",&item);
				createlist(item);
				break;
			case 2:
				printf("\nEnter the element:");
				scanf("%d",&item);
				insertbegin(item);
				break;
			case 3:
				printf("\nEnter the element:");
				scanf("%d",&item);
				insertend(item);
				break;
			case 4:
				printf("\nEnter the element:");
				scanf("%d",&item);
				insertbefore(item);
				break;
			case 5:
				printf("\nEnter the element:");
				scanf("%d",&item);
				insertafter(item);
				break;
			case 6:
				deletebegin();
				break;
			case 7:
				deleteend();
				break;
			case 8:
				deleteafter();
				break;
			case 9:
				deleteentirelist();
				break;
			case 10:
				display();
				break;
			case 11:
				exit(0);
			default:printf("\nwrong choice...\n");
		}
	}
	while(choice!=11);
}
