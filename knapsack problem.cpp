# include<stdio.h>
 
void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;
 
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 
   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }
 
   if (i < n)
      x[i] = u / weight[i];
 
   tp = tp + (x[i] * profit[i]);
 
   printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);
 
   printf("\nMaximum profit is:- %f", tp);
 
}
 
int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;
 
   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);
 
   printf("\nEnter the wts and profits of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f %f", &weight[i], &profit[i]);
   }
 
   printf("\nEnter the capacityacity of knapsack:- ");
   scanf("%f", &capacity);
 
   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }
 
   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }
 
   knapsack(num, weight, profit, capacity);#include<stdio.h>
#include<conio.h>
#define MAX 10

void main()
{
	char ele[MAX][MAX];
	int w[MAX][MAX], c[MAX][MAX], r[MAX][MAX], p[MAX], q[MAX];
	int temp=0, root, min, min1, n;
	int i,j,k,b;	
	clrscr();
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("\n");
	for(i=1; i <= n; i++)
	{
		printf("Enter the Element of %d:",i);
		scanf("%d",&p[i]);
	}
	printf("\n");
	for(i=0; i <= n; i++)
	{
		printf("Enter the Probability of %d:",i);
		scanf("%d",&q[i]);
	}
	printf("W\t\tC\t\tR\n");	
	for(i=0; i <= n; i++)
	{
		for(j=0; j <= n; j++)
		{
			if(i == j)
			{
				w[i][j] = q[i];
			 	c[i][j] = 0;
				r[i][j] = 0;
				printf("W[%d][%d]: %d\tC[%d][%d]: %d\tR[%d][%d]: %d\n",i,j,w[i][j],i,j,c[i][j],i,j,r[i][j]);
			}
		}
	}
	printf("\n");
	for(b=0; b < n; b++)
	{
		for(i=0,j=b+1; j < n+1 && i < n+1; j++,i++)
		{
			if(i!=j && i < j)
			{
				w[i][j] = p[j] + q[j] + w[i][j-1];
				
				min = 30000;
				for(k = i+1; k <= j; k++)
				{
					min1 = c[i][k-1] + c[k][j] + w[i][j];
					if(min > min1)
					{
						min = min1;
						temp = k;
					}
				}
				c[i][j] = min;
				r[i][j] = temp;
			}
			printf("W[%d][%d]: %d\tC[%d][%d]: %d\tR[%d][%d]: %d\n",i,j,w[i][j],i,j,c[i][j],i,j,r[i][j]);
		}
		printf("\n");
	}
	printf("Minimum cost = %d\n",c[0][n]);
	root = r[0][n];
	printf("Root  = %d \n",root);
	getch();
}

   return(0);
}
