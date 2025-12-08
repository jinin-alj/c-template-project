#include "semx.h"
#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int num_threads = 12;
const int semaphore_limit = 3;
semx_t semaphore;

void *thread_function(void *arg) {
  atomic_int *counter = arg;
  semx_wait(&semaphore);
  (*counter)++;
  assert(*counter <= semaphore_limit);
  usleep(10000);
  (*counter)--;
  semx_post(&semaphore);
  return NULL;
}

int main() {
  pthread_t threads[num_threads];
  semx_init(&semaphore, semaphore_limit);
  atomic_int counter = 0;
  for (int i = 0; i < num_threads; ++i) {
    pthread_create(&threads[i], NULL, thread_function, &counter);
  }
  for (int i = 0; i < num_threads; ++i) {
    pthread_join(threads[i], NULL);
  }
  semx_destroy(&semaphore);
  return 0;
}
