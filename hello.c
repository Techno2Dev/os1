#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{

	int val[10],ele;
	pid_t pid;
	char *cval[10];
	int i,j,n,temp;
	printf("\n Enter the size of array\n");
	scanf("%d",&n);
	printf("\n Enter the numbers\n");
	for(i=0;i<n;i++)
	 {
 		scanf("%d",&val[i]);
	 }
	printf("\n Elements entered are\n");
	for(i=0;i<n;i++)
	printf(" %d ",val[i]);
	{
 
	
		for(i=1;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(val[j]>val[j+1])
				{
					temp=val[j];
					val[j]=val[j+1];
					val[j+1]=temp;
				}
			}
		}
	

	printf("\n Sorted elements are\n:");

	for(i=0;i<n;i++)
	{
		printf(" %d ",val[i]);
	}
		
	printf("\n Enter element to search:");
	scanf("%d",&ele);
	val[i]=ele;
	for(i=0;i<n+1;i++)
	{
	
		char a[sizeof(int)];
		snprintf(a,sizeof(int),"%d",val[i]);
		cval[i]=malloc(sizeof(a));
		strcpy(cval[i],a);
	}
	cval[i]=NULL;
	pid=fork();
	if(pid==0)
	{
		execv(argv[1],cval);
		perror("\n Error in execv call");
	}

}
}

 
/*

[kiosk@foundation5 ~]$ gcc s2a.c -o first
[kiosk@foundation5 ~]$ gcc s2b.c -o second
[kiosk@foundation5 ~]$ ./first ./second

 Enter the size of array
6

 Enter the numbers
6
8
4
9
6
0

 Elements entered are
684960
 Sorted elements are
:046689
 Enter element to search:6

 Element found in given array[kiosk@foundation5 ~]$ */	





#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[],char *en[])
{
  	int i,j,c,arr[argc],ele;
	
	for(j=0;j<argc-1;j++)
	{
		int n=atoi(argv[j]);
		arr[j]=n;
	}
	
	ele=atoi(argv[j]);
	i=0;j=argc-1;
	c=(i+j)/2;
	while(arr[c]!=ele && i<=j)
	{
		if(ele>arr[c])
		i=c+1;
		else
		j=c-1;
		c=(i+j)/2;
	}
	if(i<=j)
	printf("\n Element found in given array");
	else
	printf("\n Elements not found in given array");
	return 0;
}

/*
[kiosk@foundation5 ~]$ gcc s2a.c -o first
[kiosk@foundation5 ~]$ gcc s2b.c -o second
[kiosk@foundation5 ~]$ ./first ./second

 Enter the size of array
6

 Enter the numbers
6
8
4
9
6
0

 Elements entered are
684960
 Sorted elements are
:046689
 Enter element to search:6

 Element found in given array[kiosk@foundation5 ~]$ 
*/

