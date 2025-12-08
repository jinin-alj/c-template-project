#include "semx.h"
#include <pthread.h>
#include <stdlib.h>

int semx_init(semx_t *sem, int initial_count) {
  if (!sem)
    return -1;

  sem->count = initial_count;
  if (pthread_mutex_init(&sem->mutex, NULL) != 0)
    return -1;
  if (pthread_cond_init(&sem->cond, NULL) != 0) {
    pthread_mutex_destroy(&sem->mutex);
    return -1;
  }
  return 0;
}

int semx_wait(semx_t *sem) {
  if (!sem)
    return -1;

  pthread_mutex_lock(&sem->mutex);

  while (sem->count == 0) {
    pthread_cond_wait(&sem->cond, &sem->mutex);
  }

  sem->count--;

  pthread_mutex_unlock(&sem->mutex);
  return 0;
}

int semx_post(semx_t *sem) {
  if (!sem)
    return -1;

  pthread_mutex_lock(&sem->mutex);

  sem->count++;
  pthread_cond_signal(&sem->cond);

  pthread_mutex_unlock(&sem->mutex);
  return 0;
}

int semx_destroy(semx_t *sem) {
  if (!sem)
    return -1;

  pthread_cond_destroy(&sem->cond);
  pthread_mutex_destroy(&sem->mutex);
  return 0;
}
