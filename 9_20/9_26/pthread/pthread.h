#ifndef _pthread_h
#define _pthread_h
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define MATH_SIZE 8
void *rank(void * arg);
pthread_mutex_t mutex;
#endif
