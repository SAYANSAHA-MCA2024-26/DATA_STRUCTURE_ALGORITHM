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
void createlinkedlist(int item)
{
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	p->data=item;
	p->next=NULL;
	start=p;
}
void insertbegin(int item)
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
	printf("\ninsert the data begin at the linked list\n");
}
void insertend(int item)
{
	NODE *p,*loc;
	p=(NODE *)malloc(sizeof(NODE));
	p->data=item;
	p->next=NULL;
	if(start==NULL)
	{
		start=p;
	}
	else
	{
		loc=start;
		while(loc->next!=NULL)
		{
			loc=loc->next;
		}
		loc->next=p;
	}
	printf("\ninsert the last node\n");
}
void deletebegin()
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
		printf("element deleted is:%d",p->data);
		free(p);
	}
	printf("\ndeleted the first node\n");
}
void deleteend()
{
	NODE *p,*loc;
	if(start==NULL)
	{
		printf("\nlist is empty\n");
	}
	else if(start->next==NULL)
	{
		p=start;
		start=NULL;
		printf("deleted element is:%d",p->data);
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
		printf("deleted element is:%d",p->data);
		free(p);
	}
	printf("\ndeleted the last elenent node\n");
}
void display()
{
	int count=0;
	NODE *curr=start;
	if(curr==NULL)
	{
		printf("\nempty list\n");
	}
	while(curr!=NULL)
	{
		printf("\ndata %d=%d",++count,curr->data);
		curr=curr->next;
	}
}
void searching()
{
	int key,flag,i=0;
	NODE *loc;
	loc=start;
	if(loc==NULL)
	{
		printf("\nlinked is empty\n");
	}
	else
	{
		printf("\nenter the search value:\n");
		scanf("%d",&key);
		while(loc!=NULL)
		{
			if(loc->data==key)
			{
				printf("\nitem found at location %d \n",i+1);  
                flag=0; 
			}
			else
			{
				flag=1;
			}
			i++;
			loc=loc->next;
		}
		if(flag==1)
		{
			printf("\nitem not found\n");
		}
	}
}
void beforeinsert(int item)
{
	NODE *p,*preptr,*ptr;
	int key;
	printf("\nenter the value before insert\n");
	scanf("%d",&key);
	if(start==NULL)
	{
		printf("overflow");
	}
	else
	{
		p=(NODE *)malloc(sizeof(NODE));
		p->data=item;
		ptr=start;
		preptr=start;
		while(ptr->data!=key)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=p;
		p->next=ptr;
	}
}
void afterinsert(int item)
{
	NODE *p,*ptr;
	int key;
	printf("\nenter the value afetr insert\n");
	scanf("%d",&key);
	if(start==NULL)
	{
		printf("overflow");
	}
	else
	{
		p=(NODE *)malloc(sizeof(NODE));
		p->data=item;
		ptr=start;
		while(ptr->data!=key)
		{
			
			ptr=ptr->next;
		}
		p->next=ptr->next;
		ptr->next=p;
	}
}
void deleteafter()
{
	NODE *p,*ptr;
	int key;
	printf("\nenter the value after delete\n");
	scanf("%d",&key);
	p=start;
	while(p->next!=NULL)
	{
		if(p->data==key)
		{
			ptr=p->next;
			p->next=ptr->next;
			free(ptr);
			break;
		}
		p=p->next;
	}
}
void deleteentirelist()
{
	NODE *temp;
	temp=start;
	if(start==NULL)
	{
		free(start);
		printf("\ndelete the entire list\n");
	}
	else
	{
		temp=temp->next;
		free(start);
		start=temp;
		printf("\ndelete the entire list\n");
	}
}
int main()
{
	int choice,item;
	do
	{
		printf("\n1. creatr the linked list\n");
		printf("\n2. insert element at the begin\n");
		printf("\n3. insert element at the end\n");
		printf("\n4. insert element at the before node\n");
		printf("\n5. insert element at the after node\n");
		printf("\n6. delete element at the begin\n");
		printf("\n7. delete element at the end\n");
		printf("\n8. delete element at the after node\n");
		printf("\n9. delete element in the entire list\n");
		printf("\n10. display the element\n");
		printf("\n11. display the searching\n");
		printf("\n12. exit\n");
		printf("\nenter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter the element:");
				scanf("%d",&item);
				createlinkedlist(item);
				break;
			case 2:
				printf("enter the element:");
				scanf("%d",&item);
				insertbegin(item);
				break;
			case 3:
				printf("enter the element:");
				scanf("%d",&item);
				insertend(item);
				break;
			case 4:
				printf("enter the element:");
				scanf("%d",&item);
				beforeinsert(item);
				break;
			case 5:
				printf("enter the element:");
				scanf("%d",&item);
				afterinsert(item);
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
				searching();
				break;
			case 12:
				exit(0);
				break;
		}
	}
	while(choice!=12);
}
