#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define SHMSZ  27
main()
{
	char c;
	int shmid;
	key_t key;
	char *shm,  *s;
	key=5678;
	if ((shmid = shmget ( key,  SHMSZ,  IPC_CREAT   |  0666)) < 0)
	{
		perror("shmget");
		exit(0);
	}
	if (( shm = shmat,(shmid, NULL, 0)) == (char *)  -1)
	{
		perror("shmat");
		exit(0);
	}
	s=shm;
	for (c='a';  c<='z';  c++)
	*s=NULL;
	exit(0);
}
