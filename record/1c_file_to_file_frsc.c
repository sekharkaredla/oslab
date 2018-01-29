#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	int fd1,fd2;
	char ch[1];
	fd1=open("first.txt",O_RDONLY);
	printf("%d\n",fd1);
	fd2=creat("second.txt",S_IREAD|S_IWRITE);
	printf("%d\n",fd2);
	if(fd1<0||fd2<0)
	{
		printf("Error");
		exit(-1);
	}
	while((read(fd1,ch,1))>0)
		{
		write(fd2,ch,1);
		printf("%c",ch[0]);
		}
		close(fd1);
		close(fd2);
		return 0;
}
