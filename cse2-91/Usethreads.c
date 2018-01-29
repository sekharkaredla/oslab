#include<stdio.h> 
#include<string.h> 
#include <pthread.h> 
void *myfunc (void *mydata); 
pthread_t theThread; 
main() 
{ 
pthread_t thread1; 
char *my1="first thread"; 
int ret1; 
ret1=pthread_create(&thread1,NULL,&myfunc,(void*)my1); 
printf("main function after pthread\n"); 
pthread_join(thread1,NULL); 
printf("first thread ret1=%d\n",ret1); 
if(pthread_equal(thread1,theThread)) 
{ 
printf("success\n"); 
} 
} 

void *myfunc (void *mydata) 
{ 
char *msg; 
msg=(char*)mydata; 
int i; 
for(i=0;i<10;i++) 
{ 
printf("%s%d\n",msg,i); 
sleep(1); 
theThread=pthread_self(); 
} 
pthread_exit(NULL); 
} 
