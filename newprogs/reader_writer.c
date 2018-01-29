#include<stdio.h>
#include<semaphore.h>
sem_t mutex;
sem_t db;
int readercount=0;
pthread_t reader1,reader2,writer1,writer2;
void *reader(void *);
void *writer(void *);
void main()
{
sem_init(&mutex,0,1);
sem_init(&db,0,1);
while(1)
{
pthread_create(&reader1,NULL,reader,"1");
pthread_create(&reader2,NULL,reader,"2");
pthread_create(&writer1,NULL,writer,"1");
pthread_create(&writer2,NULL,writer,"2");
}
}
void *reader(void *p)
{
int temp;
sem_getvalue(&mutex,&temp);
printf("in reader : %s prevoius value %d\n",(char *)p,temp);
sem_wait(&mutex);
sem_getvalue(&mutex,&temp);
printf("Mutex acquired by reader %d\n",temp);
readercount++;
if(readercount==1) sem_wait(&db);
sem_post(&mutex);
sem_getvalue(&mutex,&temp);
printf("Mutex returned by reader %d\n",temp);
printf("Reader %s is Reading\n",(char *)p);
sleep(3);
sem_wait(&mutex);
printf("Reader %s Completed Reading\n",(char *)p);
readercount--;
if(readercount==0) sem_post(&db);
sem_post(&mutex);
}

void *writer(void *p)
{
printf("Writer : %s is Waiting\n",(char *)p);
sem_wait(&db);
printf("Writer %s is writing\n",(char *)p);
sem_post(&db);
sleep(2);
}
