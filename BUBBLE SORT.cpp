#include<stdio.h>
int main()
{
	int n,i,j,swap;
	int arr[100];
	printf("enter the range of array value:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("element is [%d]:",i);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=swap;
			}
		}
	}
	printf("\nAfter the bubble sort\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
