#include <stdio.h>
// #include <stdatomic.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
// #define INCREMENTS_PER_THREAD 10000

void log_process(const char *data) {
    FILE *file = fopen("log.txt", "a");
    if (file != NULL) {
        fprintf(file, "-----new entry----:\n");
        fprintf(file, "%s\n", data);
        fprintf(file, "------end entry---\n");
        fclose(file);
    }
}
// void *increment_counter(void *args) {
//    _Atomic int *counter = (int *)args;
//    for (int i = 0; i < INCREMENTS_PER_THREAD; i++) {
//      (*counter)++;
//    }
//    return NULL;
// }

void *thread_function(void *arg) {
    pthread_mutex_t *fm = arg;
    pthread_mutex_lock(fm);
    const char *data = "Some arbitrary data";
    log_process(data);
    pthread_mutex_unlock(fm);
    return NULL;
}

int main() {
    pthread_mutex_t file_mutex;
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&file_mutex, NULL);
    // _Atomic int counter = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &file_mutex); //&counter);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&file_mutex);
}