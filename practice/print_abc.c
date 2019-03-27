#include <stdio.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

//方式一：
sem_t sem1,sem2,sem3;

void* printA(void* arg){ 
	while( 1){ 
		sem_wait(&sem1);
		printf( "A       --by thread%ld\n", pthread_self());
		usleep( 100000);
		sem_post(&sem2);
	}
}
void* printB(void* arg){ 
	while( 1){ 
		sem_wait(&sem2);
		printf( "B       --by thread%ld\n", pthread_self());
		usleep( 100000);
		sem_post(&sem3);
	}
}
void* printC(void* arg){ 
	while(1){ 
		sem_wait(&sem3);
		printf( "C       --by thread%ld\n", pthread_self());
		usleep( 10000);
		sem_post(&sem1);
	}
}
int main( void )
{ 
	sem_init(&sem1, 0, 1);
	sem_init(&sem2, 0, 0);
	sem_init(&sem3, 0, 0);

	pthread_t pid1,pid2,pid3;
	pthread_create(&pid1, NULL, printA, NULL);
	pthread_create(&pid2, NULL, printB, NULL);
	pthread_create(&pid3, NULL, printC, NULL);

	pthread_join(pid1, NULL);
	pthread_join(pid2, NULL);
	pthread_join(pid3, NULL);
	return 0;
}


