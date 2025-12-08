#include "barrier.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int num_threads = 5;
barrier_t barrier;

void *thread_function(void *arg) {
  int thread_id = (int)(size_t)arg;
  
  printf("Thread %d: Performing work before barrier\n", thread_id);
  usleep(rand() % 100000); // Simulate work
  printf("Thread %d: Waiting at barrier\n", thread_id);
  barrier_wait(&barrier);
  printf("Thread %d: Passed the barrier\n", thread_id);
  return NULL;
}
int main() {
  pthread_t threads[num_threads];
  barrier_init(&barrier, num_threads);
  for (int i = 0; i < num_threads; ++i) {
    pthread_create(&threads[i], NULL, thread_function, (void *)(size_t)i);
  }
  for (int i = 0; i < num_threads; ++i) {
    pthread_join(threads[i], NULL);
  }
  barrier_destroy(&barrier);
  return 0;
}