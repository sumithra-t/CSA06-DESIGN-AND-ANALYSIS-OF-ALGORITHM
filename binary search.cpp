#include<stdio.h>
int main()
{
	int i,low,high,mid,n,key,a[100];
	printf("Enter the no.of elements");
	scanf("%d",&n);
	printf("Enter the integers");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		}
		printf("Enter the value to find:");	
		scanf("%d",&key);
		low=0;
		high=n-1;
		mid=(low+high)/2;

		while(low<=high)
		{
			if(a[mid]<key)
			{
				low=mid+1;
			}
			else
			if(a[mid]==key)
			{
				printf("%d found at location %d",key,mid+1);
				break;
			}
			else
			{
				high=mid-1;
			}
			mid=(low+high)/2;
		}
		if(low>high)
		{
			printf("Not found! %d is not present in the list",key);
		}
		return 0;
	}
