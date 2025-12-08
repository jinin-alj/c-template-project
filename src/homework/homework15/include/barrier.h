#pragma once
#include <pthread.h>
typedef struct {
  int threshold;
  int waiting;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} barrier_t;
/**
 * @brief Initialize the barrier for the given number of threads.
 * @param barrier Pointer to the barrier to initialize.
 * @param count The number of threads that must call wait before any can
 * proceed.
 * @return 0 on success, non-zero on failure.
 */
int barrier_init(barrier_t *barrier, int count);
/**
 * @brief Wait at the barrier until the required number of threads have called
 * wait.
 * @param barrier Pointer to the barrier to wait on.
 * @return 0 on success, non-zero on failure.
 */
int barrier_wait(barrier_t *barrier);
/**
 * @brief Destroy the barrier, freeing any associated resources.
 * @param barrier Pointer to the barrier to destroy.
 * @return 0 on success, non-zero on failure.
 */
int barrier_destroy(barrier_t *barrier);