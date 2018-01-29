#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int fd;
	int n_char=0;
	char buffer[1];
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		exit(-1);
	}
	while((n_char=read(fd,buffer,1))!=0)
	{
		//printf("%d",n_char);
		write(1,buffer,n_char);
	}
	return 0;
}
