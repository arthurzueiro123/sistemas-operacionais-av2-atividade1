#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//questao 2
int saldo = 0;
int turn = 1;
pthread_mutex_t semaforo = PTHREAD_MUTEX_INITIALIZER;


void* depositar(void* v)
{
    int* x = (int*)v;
    int tid = *x;
    pthread_mutex_lock(&semaforo);
    for(int i=0;i<10000;i++)
    {

        saldo = saldo+1;
        printf("thread: %d.\n",tid);


    }
    pthread_mutex_unlock(&semaforo);
}

int main()
{
    int tid1 = 1;
    int tid2 = 2;
    int tid3 = 3;
    int tid4 = 4;

    pthread_t thread_1;
    pthread_t thread_2;
    pthread_t thread_3;
    pthread_t thread_4;




    pthread_create(&thread_1,NULL,&depositar,&tid1);


    pthread_create(&thread_2,NULL,&depositar,&tid2);

    pthread_create(&thread_3,NULL,&depositar,&tid3);

    pthread_create(&thread_4,NULL,&depositar,&tid4);






    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    pthread_join(thread_3,NULL);
    pthread_join(thread_4,NULL);

    printf("Saldo Final: %d.",saldo);

    return 0;
}
