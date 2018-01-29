#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>
int main(int argc,char *argv[])
{
	int pid,childpid,status;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"fork failed");
		return 1;
	}
	else if(pid==0)
	{
		execlp("/bin/ls","ls",NULL);
		_exit(0);
	}
	else
	{
		wait(NULL);
		printf("child process complete\n");
	}
	return 0;
}
