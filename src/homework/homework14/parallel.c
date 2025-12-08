#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// the stuff from the notes
float *generate_random_list(int size) {
  float *list = malloc(size * sizeof(float));
  for (int i = 0; i < size; i++) {
    list[i] = (float)rand() / RAND_MAX; // Random float between 0 and 1
  }
  return list;
}

// my solution
typedef struct {
  float *list;
  int start;
  int end;
  double partial_sum;
} ThreadData;

void *thread_sum(void *arg) {
  ThreadData *data = (ThreadData *)arg;
  double sum = 0.0;
  for (int i = data->start; i < data->end; i++) {
    sum += data->list[i];
  }
  data->partial_sum = sum;
  return NULL;
}

double average_single(float *list, int size) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += list[i];
  }
  return sum / size;
}

double average_parallel(float *list, int size, int num_threads) {
  pthread_t threads[num_threads];
  ThreadData args[num_threads];
  int chunk = size / num_threads;
  for (int i = 0; i < num_threads; i++) {
    args[i].list = list;
    args[i].start = i * chunk;
    args[i].end = (i == num_threads - 1) ? size : (i + 1) * chunk;

    pthread_create(&threads[i], NULL, thread_sum, &args[i]);
  }
  double total = 0.0;
  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
    total += args[i].partial_sum;
  }
  return total / size;
}




int main() {
  int size = 1000000;
  float *list = generate_random_list(size);

  double avg1 = average_single(list, size);
  double avg2 = average_parallel(list, size, 4);

  printf("Single-threaded:   %f\n", avg1);
  printf("Multi-threaded:    %f\n", avg2);

  free(list);
  return 0;
}