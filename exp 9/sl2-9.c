#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#define bufsize 1000
int main(int argc,char *argv[])
{
	int ifd,ofd;
	ssize_t retin,retout;
	char buff[bufsize];
	if(argc!=3)
	{
		printf("\nError while copying the file");
		return 1;
	}		
	ifd=open(argv[1],O_RDONLY);
	if(ifd==-1)
	{
		perror("\nOpen");
		return 2;
	}
	ofd=open(argv[2],O_WRONLY);
	if(ofd==-1)
	{
		perror("\nOpen");
		return 3;
	}
	while((retin=read(ifd,&buff,bufsize))>0)
	{
		retout=write(ofd,&buff,(ssize_t)retin);
		if(retout!=retin)
		{
			perror("\nWrite");
			return 4;
		}
		
	}
	close(ifd);
	close(ofd);
	return 0;
}

/*
gcc sl2-9.c -o p1
sl2-9.c: In function ‘main’:
sl2-9.c:27:15: warning: implicit declaration of function ‘read’ [-Wimplicit-function-declaration]
  while((retin=read(ifd,&buff,bufsize))>0)
               ^
sl2-9.c:29:10: warning: implicit declaration of function ‘write’ [-Wimplicit-function-declaration]
   retout=write(ofd,&buff,(ssize_t)retin);
          ^
sl2-9.c:37:2: warning: implicit declaration of function ‘close’ [-Wimplicit-function-declaration]
  close(ifd);
  ^
exam@exam:~$ ./p1 src.txt dest.txt
*/
