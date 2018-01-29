#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
void main()
{
	int fd[2];
	pipe(fd);
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
	printf("error");
	exit(-1);
	}
	else if(pid==0)
	{
	printf("child writing\n");
	close(fd[0]);
	write(fd[1],"HELLO",sizeof("HELLO"));
	}
	else
	{
	char buf[10];
	//buf[0]=' ';
	close(fd[1]);
	printf("parent process\n");
	read(fd[0],buf,sizeof(buf));
	printf("%s",buf);
	}
}
