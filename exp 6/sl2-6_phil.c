#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
pthread_mutex_t work_mutex[5];
void *phil1()
{
	while(1)
	{
		pthread_mutex_lock(&work_mutex[0]);
		pthread_mutex_lock(&work_mutex[4]);
		printf("phi1 is eating\n");
		sleep(3);
		pthread_mutex_unlock(&work_mutex[4]);
		pthread_mutex_unlock(&work_mutex[0]);
		printf("phi1 is realizing the fork\n");
		printf("phi1 is thinking\n");
	}
	pthread_exit(0);
}
void *phil2()
{
	while(1)
	{
		pthread_mutex_lock(&work_mutex[0]);
		pthread_mutex_lock(&work_mutex[1]);
		printf("phi2 is eating\n");
		sleep(1);
		pthread_mutex_unlock(&work_mutex[1]);
		pthread_mutex_unlock(&work_mutex[0]);
		printf("phi2 is realizing the fork\n");
		printf("phi2 is thinking\n");
	}
	pthread_exit(0);
}
void *phil3()
{
	while(1)
	{
		pthread_mutex_lock(&work_mutex[1]);
		pthread_mutex_lock(&work_mutex[2]);
		printf("phi3 is eating\n");
		sleep(1);
		pthread_mutex_unlock(&work_mutex[2]);
		pthread_mutex_unlock(&work_mutex[1]);
		printf("phi3 is realizing the fork\n");
		printf("phi3 is thinking\n");
	}
	pthread_exit(0);
}
void *phil4()
{
	while(1)
	{
		pthread_mutex_lock(&work_mutex[2]);
		pthread_mutex_lock(&work_mutex[3]);
		printf("phi4 is eating\n");
		sleep(1);
		pthread_mutex_unlock(&work_mutex[3]);
		pthread_mutex_unlock(&work_mutex[2]);
		printf("phi4 is realizing the fork\n");
		printf("phi4 is thinking\n");
	}
	pthread_exit(0);
}
void *phil5()
{
	while(1)
	{
		pthread_mutex_lock(&work_mutex[3]);
		pthread_mutex_lock(&work_mutex[4]);
		printf("phi5 is eating\n");
		sleep(1);
		pthread_mutex_unlock(&work_mutex[4]);
		pthread_mutex_unlock(&work_mutex[3]);
		printf("phi5 is realizing the fork\n");
		printf("phi5 is thinking\n");
	}
	pthread_exit(0);
}
int main()
{
	int res,i;
	pthread_t phi1,phi2,phi3,phi4,phi5;
	for(i=0;i<5;i++)
	{
		res=pthread_mutex_init(&work_mutex[i],NULL);
		if(res!=0)
		{
			printf("mutex not initialize");
		}
	}
	pthread_create(&phi1,NULL,phil1,NULL);
	pthread_create(&phi2,NULL,phil2,NULL);
	pthread_create(&phi3,NULL,phil3,NULL);
	pthread_create(&phi4,NULL,phil4,NULL);
	pthread_create(&phi5,NULL,phil5,NULL);
	pthread_join(phi1,NULL);
	pthread_join(phi2,NULL);
pthread_join(phi3,NULL);
	pthread_join(phi4,NULL);
	pthread_join(phi5,NULL);
	return 0;
}




/* gcc s6.c -o dgfd -lpthread
  ./dgfd
phi1 is eating
phi3 is eating
phi3 is realizing the fork
phi3 is thinking
phi5 is eating
phi5 is realizing the fork
phi5 is thinking
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
phi1 is thinking
phi1 is eating
phi1 is realizing the fork
*/


