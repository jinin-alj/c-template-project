#include "barrier.h"
#include <pthread.h>
#include <stdlib.h>

int barrier_init(barrier_t *barrier, int count) {
  if (!barrier || count <= 0)
    return -1;
  barrier->threshold = count;
  barrier->waiting = 0;
  pthread_mutex_init(&barrier->mutex, NULL);
  pthread_cond_init(&barrier->cond, NULL);
  return 0;
}

int barrier_wait(barrier_t *barrier) {
  if (!barrier)
    return -1;
  pthread_mutex_lock(&barrier->mutex);
  barrier->waiting++;
  if (barrier->waiting < barrier->threshold) {
    pthread_cond_wait(&barrier->cond, &barrier->mutex);
  } else {
    barrier->waiting = 0;
    pthread_cond_broadcast(&barrier->cond);
  }
  pthread_mutex_unlock(&barrier->mutex);
  return 0;
}

int barrier_destroy(barrier_t *barrier) {
  if (!barrier)
    return -1;
  pthread_mutex_destroy(&barrier->mutex);
  pthread_cond_destroy(&barrier->cond);
  return 0;
}