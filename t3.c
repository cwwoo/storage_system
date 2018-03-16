#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

typedef struct __myarg_t {
	int a;
	int b;
} myarg_t;

typedef struct __myret_t {
	int x;
	int y;
} myarg_t;

void *mythread(void *arg){
	myarg_t *m = (myarg_t *) arg;
	printf("%d %d\n", m->a, m->b);
	myret_t r;
	r.x = 1;
	r.y = 2;
	return (void *) &r;
}

void *mythread(void *arg){
	int m = (int) arg;
	printf("%d\n", m);
	return (void *)(arg+1);
}

int main(int argc, char *argv[]){
	pthread_t p;
	int rc, m;
	pthread_create(&p, NULL, mythread, (void *) 100);
	pthread_join(p, (void **) &m);
	printf("returned %d\n", m);
	return 0;
}


