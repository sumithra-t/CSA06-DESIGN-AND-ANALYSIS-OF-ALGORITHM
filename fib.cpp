#include<stdio.h>
int fibonacci(int n)
{
	if(n==0||n==1)
	{
		return n;
	}
	else
	{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}

int main()
{
	int n,i;
	printf("Enter the no of terms");
	scanf("%d",&n);
	printf("fibonacci series:");
	for(i=0;i<=n;i++)
	{
		printf("%d",fibonacci(i));
	}
	return 0;
}
