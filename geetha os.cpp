#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
pthread_mutex_tx,wsem;
pthread_ttid;
int countread;
void starting()
{
pthread_mutex_init(&x,NULL);
pthread_mutex_init(&wsem,NULL);
countread=0;
}
void * reader (void * param)
{
int waittime;
waittime = rand() % 5;
printf("\n\t\tReader is trying to enter in the critical section");
pthread_mutex_lock(&x);
countread++;
if(countread==1)
pthread_mutex_lock(&wsem);
printf("\n\t\t%d Reader is inside ",countread);
pthread_mutex_unlock(&x);
sleep(waittime);
pthread_mutex_lock(&x);
countread--;
if(countread==0)
pthread_mutex_unlock(&wsem);
pthread_mutex_unlock(&x);
printf("\n\t\tReader is Leaving");
}
void * writer (void * param)
{
int waitT;
waitT=rand() % 3;
printf("\n\t\tWriter is trying to enter in the section");
pthread_mutex_lock(&wsem);
printf("\n\t\tWrite has entered");
sleep(waitT);
pthread_mutex_unlock(&wsem);
printf("\n\t\tWriter is leaving");
sleep(30);
exit(0);
}

int main()
{
int reader1,writer1,i;
printf("\n\t\tEnter the no of readers you want: ");
scanf("%d",&reader1);
printf("\n\t\tenter the no of writers you want: ");
scanf("%d",&writer1);
	for(i=0;i<n1;i++)
	{
		pthread_create(&tid,NULL,reader,NULL);
	}
	for(i=0;i<n2;i++)
	{
			pthread_create(&tid,NULL,writer,NULL);
	}	//thread creation 
sleep(20);	// process will sleep for 20 sec
exit(0);
}
