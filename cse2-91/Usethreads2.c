#include<stdio.h> 
#include<string.h> 
#include <pthread.h> 
void *myfunc (void *mydata); 
main() 
{ 
pthread_t thread1,thread2; 
char *my1="first thread"; 
char *my2="second thread"; 
int ret1,ret2; 
ret1=pthread_create(&thread1,NULL,&myfunc,(void*)my1); 
ret2=pthread_create(&thread2,NULL,&myfunc,(void*)my2); 
printf("main function after pthread\n"); 
pthread_join(thread1,NULL); 
pthread_join(thread2,NULL); 
printf("first thread ret1=%d\n",ret1); 
printf("second thread ret1=%d\n",ret2); 
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
} 
return NULL; 
} 
