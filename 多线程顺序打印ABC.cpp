
#include<stdio.h> 
#include<pthread.h> 



void *secondFunc(void *);
void *thirdFunc(void *);



void *firstFunc(void *args)
{

	pthread_t id2;

	pthread_create(&id2, NULL, &secondFunc, NULL);

	pthread_join(id2, NULL);




	printf("C\n");
}
void *secondFunc(void *args)
{

	pthread_t id3;

	pthread_create(&id3, NULL, &thirdFunc, NULL);

	pthread_join(id3, NULL);

	printf("B\n");
}



void *thirdFunc(void *args)
{

	printf("A\n");
}



int main()
{

	pthread_t id1;

	pthread_create(&id1, NULL, &firstFunc, NULL);

	pthread_join(id1, NULL);




	return 0;
}

/*
#include<stdio.h>
#include<sys/types.h>
#include<semaphore.h>
#include<pthread.h>

sem_t sem_id1, sem_id2, sem_id3;

void* func1(void*);    //声明
void* func2(void*);
void* func3(void*);

int main(void) {
	sem_init(&sem_id1, 0, 1);    //活动
	sem_init(&sem_id2, 0, 0);
	sem_init(&sem_id3, 0, 0);

	pthread_t pthread_id1, pthread_id2, pthread_id3;
	pthread_create(&pthread_id1, NULL, func1, NULL);
	pthread_create(&pthread_id2, NULL, func2, NULL);
	pthread_create(&pthread_id3, NULL, func3, NULL);

	pthread_join(phread_id1, NULL);
	pthread_join(phread_id1, NULL);
	pthread_join(phread_id1, NULL);

	return 0;
}

void *func1(void*) {
	sem_wait(sem_id1);
	printf("A\n");
	sem_post(sem_id2);
}
void *func2(void*) {
	sem_wait(sem_id2);
	printf("B\n");
	sem_post(sem_id3);
}
void *func3(void*) {
	sem_wait(sem_id3);
	printf("C\n");
	sem_post(sem_id1);
}
*/