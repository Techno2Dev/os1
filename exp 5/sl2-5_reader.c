#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
pthread_mutex_t x,wsem;
pthread_t tid;
int readcount;

void initialize()
{
	pthread_mutex_init(&x,NULL);
	pthread_mutex_init(&wsem,NULL);
	readcount=0;
}
void * reader(void * param)
{
	int waittime;
	waittime=rand() % 5;
	printf("\nReader is trying to enter");
	pthread_mutex_lock(&x);
	readcount++;	
	if(readcount==1)
		pthread_mutex_lock(&wsem);
		printf("\nReader is inside",readcount);
		pthread_mutex_unlock(&x);
		sleep(waittime);
		pthread_mutex_lock(&x);
		readcount--;
	if(readcount==0)
		pthread_mutex_unlock(&wsem);
		pthread_mutex_unlock(&x);
		printf("\nReader is leaving");
}
void * writer (void * param)
{
	int waittime;
	waittime=rand() % 3;
	printf("\n Witer is trying to enter");
	pthread_mutex_lock(&wsem);
	printf("\n Witer has Entered");
	sleep(waittime);
	pthread_mutex_unlock(&wsem);
	printf("\n Writer is Leaving");
	sleep(30);
}
int main()
{
	int n1,n2,i;
	printf("\n Enter the no. of Readers:-");
	scanf("%d",&n1); 
	printf("\n Enter the no. of Writers:-");
	scanf("%d",&n2);
	for(i=0;i<n1;i++)
	pthread_create(&tid,NULL,reader,NULL);
	for(i=0;i<n2;i++)
	pthread_create(&tid,NULL,writer,NULL);
	sleep(30);
	exit(0);
}



/* 
	OUTPUT
exam@exam:~$ gcc sl2-5.c -o sl5 -lpthread   ^
exam@exam:~$ ./sl5

 Enter the no. of Readers:-3

 Enter the no. of Writers:-2

Reader is trying to enter
Reader is inside
Reader is trying to enter
Reader is inside
 Witer is trying to enter
Reader is trying to enter
Reader is inside
 Witer is trying to enter
Reader is leaving
Reader is leaving
Reader is leaving
 Witer has Entered
 Writer is Leaving
 Witer has Entered
 Writer is Leavingexam@exam:~$ 
*/

