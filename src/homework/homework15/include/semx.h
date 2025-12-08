#pragma once
#include <pthread.h>
typedef struct {
  int count;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} semx_t;
/**
 * @brief Initialize the semaphore with the given initial count.
 * @param sem Pointer to the semaphore to initialize.
 * @param initial_count The initial count for the semaphore.
 * @return 0 on success, non-zero on failure.
 */
int semx_init(semx_t *sem, int initial_count);
/**
 * @brief Decrement (wait) the semaphore.
 * If the count is zero, block until it becomes positive.
 * @param sem Pointer to the semaphore to wait on.
 * @return 0 on success, non-zero on failure.
 */
int semx_wait(semx_t *sem);
/**
 * @brief Increment (post) the semaphore, potentially unblocking a waiting
 * thread.
 * @param sem Pointer to the semaphore to post.
 * @return 0 on success, non-zero on failure.
 */
int semx_post(semx_t *sem);
/**
 * @brief Destroy the semaphore, freeing any associated resources.
 * @param sem Pointer to the semaphore to destroy.
 * @return 0 on success, non-zero on failure.
 */
int semx_destroy(semx_t *sem);