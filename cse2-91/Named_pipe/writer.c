#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
void main(int argc,char *argv[])
{
	char *s="/tmp/testfifo";
	int fd;
	mkfifo(s,0666);
	fd=open(s,O_WRONLY);
	write(fd,argv[1],sizeof(argv[1]));
	close(fd);
	unlink(s);
}
