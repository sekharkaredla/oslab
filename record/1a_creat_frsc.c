
#include<stdio.h>		/*header file for main function*/
#include<sys/types.h>	 	
#include<sys/stat.h>	/*header files for creat() system call*/
#include<fcntl.h>		
int main()
{
	int fd;		/*creating 2 file descriptors*/
	int fd1;
	fd=creat("first.txt",S_IREAD|S_IWRITE);	/*creating 2 files which */
	fd1=creat("second.txt",S_IREAD|S_IWRITE);      //returns file descriptors
	printf("%d\n",fd);
	printf("%d\n",fd1);
	if(fd==-1)		/*checking whether file descriptor is negative or not*/
		printf("ERROR\n");
	else
		printf("SUCCESS\n");
	close(fd);			/*closing the file descriptors*/
	close(fd1);
}
