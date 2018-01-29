#include<stdio.h>
#include<unistd.h>
int main()
{
	int a=2;
	pid_t pid;
	pid=fork();
	printf("%d\n",pid);
	if(pid<0)
	{
		printf("Error");
	}
	else if(pid==0)
	{
		sleep(10);
		printf("child process \t a is : ");
		printf("%d\n",++a);
		printf("I am the child and my process id is %d\n",getpid());
		printf("I am the child and my parent process id is %d\n",getpid());
	}
	else
	{
		printf("parent process \t a is : ");
		printf("%d\n",--a);
		printf("I am the parent and my process id is %d\n",getpid());
		printf("I am the parent and my child process id is %d\n",pid);
		
	}
	printf("exiting with x=%d\n",a);
}
