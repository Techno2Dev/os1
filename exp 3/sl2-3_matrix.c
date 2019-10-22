#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
int a[10][10],b[10][10],c[10][10],k=10;
void *matrix(void *parameter);
struct v
{
	int i,j;
}*data;
int main()
{
	int ret,i,j,k,n,m,p,q;
	printf("\n Enter Size of 1st Matrix:-\n");
	scanf("%d%d",&m,&q);
	printf("\n Enter Elements of 1st Matrix:-\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n Enter Elements of 2st Matrix:-\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			struct v *data=(struct v*)malloc(sizeof(struct v));
			data->i=i;
			data->j=j;
			pthread_t tid;
			pthread_create(&tid,NULL,matrix,data);
			pthread_join(tid,NULL);
		}
	}
	printf("\nThe Matrix is:-\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	pthread_exit(0);
}
void *matrix(void *parameter)
{
	struct v *data=parameter;
	int n,sum=0;
	for(n=0;n<k;n++)
	{
		sum+=a[data->i][n]*b[n][data->j];
	}
	c[data->i][data->j]=sum;
	pthread_exit(0);
}





/* OUTPUT
exam@exam:~$ gcc sl2-3.c -o xy -lpthread
exam@exam:~$ ./xy

 Enter Size of 1st Matrix:-
2 2

 Enter Elements of 1st Matrix:-
1 1 
2 2

 Enter Elements of 2st Matrix:-
2 2
3 3

The Matrix is:-
5	5	
10	10	
exam@exam:~$ 

*/




