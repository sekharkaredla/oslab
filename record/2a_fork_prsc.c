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
                printf("fork failed");
        }
        else if(pid==0)
        {
                printf("child process \t a is : ");
                printf("%d\n",++a);
        }
        else
        {
                printf("parent process \t a is :  ");
                printf("%d\n",--a);
        }
        printf("exiting with x=%d\n",a);
}

