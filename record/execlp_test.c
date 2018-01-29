#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid;
	int status;
	pid=fork();
	if(pid<0)
	exit(-1);
	else if(pid==0)
	{
	execlp("/bin/echo","echo","sekhar karedla cse2",NULL);
	exit(1);
	}
	else
	{
	int childid=wait(&status);
	exit(2);
	}
return 0;
}
