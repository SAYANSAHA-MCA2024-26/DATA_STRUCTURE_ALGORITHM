#include<stdio.h>
int main()
{
	int i,n,item,loc=-1;
	int arr[100];
	printf("enter the number of element:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("element is [%d]:",i);
		scanf("%d",&arr[i]);
	}
	printf("\nenter the searching element:");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
		if(item==arr[i])
		{
			loc=i;
			break;
		}
	}
	if(loc>=0)
	{
		printf("%d element found the %d position",item,loc+1);
	}
	else
	{
		printf("\nitem is not found\n");
	}
}
