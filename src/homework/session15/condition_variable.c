#include <stdio.h>
// #include <stdatomic.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
// #define INCREMENTS_PER_THREAD 10000
// structs wait for a condition before something happens. 
// void *increment_counter(void *args) {
//    _Atomic int *counter = (int *)args;
//    for (int i = 0; i < INCREMENTS_PER_THREAD; i++) {
//      (*counter)++;
//    }
//    return NULL;
// }
_Atomic int shared_data = 0;
pthread_mutex_t mutex;
pthread_cond_t cond_var;

void *thread_function(void *arg) {
    size_t thread_id = *(size_t *)arg;
    pthread_mutex_lock(&mutex);
    while (shared_data <= thread_id) {
        pthread_cond_wait(&cond_var, &mutex);
    }
    shared_data ++;
    // z means unsigned big thing.
    printf("Thread %zu: shared_data = %d\n", thread_id, shared_data);
    pthread_cond_broadcast(&cond_var);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_var, NULL);
    // _Atomic int counter = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &i);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);
}