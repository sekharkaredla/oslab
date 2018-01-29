#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#define BUF 1024
void main(int argc,char *argv[])
{
	char r[BUF];
	char *s="/tmp/testfifo";
	int fd;
	fd=open(s,O_RDONLY);
	read(fd,r,BUF);
	printf("\n%s",r);
	close(fd);
}
