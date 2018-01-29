#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int pid;
	int status;
	pid=fork();
	if(pid<0)
	exit(-1);
	else if(pid==0)
	{
	
	execv("/bin/echo",argv);
	exit(1);
	}
	else
	{
	int childid=wait(&status);
	exit(2);
	}
return 0;
}
