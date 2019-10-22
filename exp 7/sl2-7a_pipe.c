#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
	int argc;
	char *argv[100];
	{
		int p2c[2],c2p[2];
		pid_t cpid;
		char bufp2c[200],bufc2p[200],fnm[100],str[1000];
		FILE *fp, *fp1;
		if(pipe(p2c)==-1)
		{
			perror("pipes");
			exit(0);
		} 
		if(pipe(c2p)==-1)
		{
			perror("pipes");
			exit(0);
		}
		cpid=fork();
		if(cpid==-1)
		{
			perror("fork");
			exit(0);
		}	
		if(cpid==0)
		{
			close(p2c[1]);
			read(p2c[0],bufp2c,20);
			close(p2c[0]);
			fp=fopen(bufp2c,"r");
			printf("\nChild Process\n");
			while(fscanf(fp,"%s",str)!=EOF)
			{
				printf("%s",str);
			}
			fclose(fp);
			close(c2p[0]);
			write(c2p[1],str,1000);
			close(c2p[1]);
			exit(0);		
		}
		else
		{
			printf("\nParent Process\n");
			printf("\nEnter the file path:-");
			scanf("%s",fnm);
			close(p2c[0]);	
			write(p2c[1],fnm,15);
			sleep(1);
			printf("\nParent Process\n");
			close(c2p[1]);
			read(c2p[0],bufc2p,1000);
			close(c2p[1]);
			printf("%s",bufc2p);
			exit(0);
		}
	}
	return 0;
}


/* Output

gedit sl2-7.c 
exam@exam:~$ gcc sl2-7.c -o r
exam@exam:~$ ./r

Parent Process

Enter the file path:-a.txt

Child Process
helloHowareyou?????
Parent Process
you?????exam@exam:~$ 
*/ 
