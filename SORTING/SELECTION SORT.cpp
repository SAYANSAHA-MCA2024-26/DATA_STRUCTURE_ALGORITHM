#include<stdio.h>
int main()
{
	int n,swap,i,j,min;
	int arr[100];
	printf("enter the range of array value:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("element is [%d]:",i);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			swap=arr[i];
			arr[i]=arr[min];
			arr[min]=swap;
		}
	}
	printf("\nAfter the selection sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
