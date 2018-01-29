#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
void main(int argc,char *argv[])
{
        int fd1[2],fd2[2];
        pipe(fd1);
	pipe(fd2);
        pid_t pid;
	char s[]="karthik dsa;kjf;lkjdsgfkjdsgkjbds";
        pid=fork();
	char buf[100];
        if(pid<0)
        {
        printf("error");
        exit(-1);
        }
        else if(pid==0)
        {
        printf("child process writing\n");
        close(fd1[0]);
        write(fd1[1],s,sizeof(s));
	exit(0);
        }
        else
        {
        //buf[0]=' ';
        close(fd1[1]);
	wait(NULL);
        printf("parent process reading\n");
        read(fd1[0],buf,sizeof(buf));
        printf("%s",buf);
        }
}


