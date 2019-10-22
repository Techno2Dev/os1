#include<stdio.h>
#include<sys/types.h>
int main()
{
	int a[10],temp=0,n,i,j,min;
	printf("\nEnter how many no. u want:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nArray is:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}

		pid_t pid=fork();

	if(pid==0)
	{
		printf("\n Hello I am child process");
		printf("\n My Process id is  : %d",getpid());
		printf("\nParent process id is  : %d",getppid()); 		
		for(i=0;i<n;i++)
		{
			j=i;
			while(j>0&&a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				j--;
			}
		}
		printf("\nSorted Array using Insertion sort is:");
		for(i=0;i<n;i++)
		{
			printf("%d\n",a[i]);
		}
	}	
		else if(pid>0)
		{
			printf("\n Hello I am Parent process");
			waitpid(-1,NULL,0);			
			printf("\n My Process id is : %d ",getpid());
			printf("\nChild process id is :  %d ",pid); 	
			for(i=0;i<n;i++)
				{
					min=i;
					for(j=i+1;j<n;j++)
					{
						if(a[j]<a[min])
						{
							min=j;
						}
					}
						temp=a[min];
						a[min]=a[i];
						a[i]=temp;
				}
				printf("\nSorted Array using Selection sort is:");
				for(i=0;i<n;i++)
				{
					printf("%d\n",a[i]);
				}
		}
else
{
		printf("\nError");
return 1;
}
}

