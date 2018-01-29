#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int fd1=open("1.txt",O_RDWR);
	printf("%d",fd1);
	char buffer[1];
	buffer[0]='1';
	printf("enter the data : (press # to exit)");
	do
	{
	scanf("%c",&buffer[0]);
	if(buffer[0]!='#')
	write(fd1,buffer,1);
	}while(buffer[0]!='#');
	close(fd1);
	int fd2=open("1.txt",O_RDWR);
	lseek(fd2,2*sizeof(char),0);int k;
	do
	{
	k=read(fd2,&buffer[0],1);
	if(k!=0)
	printf("%c",buffer[0]);
	}while(k!=0);
return 0;
}
	


