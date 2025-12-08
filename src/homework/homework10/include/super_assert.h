#pragma once
#include <stdio.h>
#include <stdlib.h>

#ifndef NDEBUG
#define super_assert(expr, msg) (void(0))
#else
#define super_assert(expr, msg)
    do {                                                           \
        int ok = (expr);                                           \
        if (SUPER_ASSERT_VERBOSE == 1) {                           \
            printf("[%s:%d in %s] ", __FILE__, __LINE__, __func__); \
        }                                                          \
        if (SUPER_ASSERT_TRACE == 1) {                             \
            printf("super_assert(trace): (%s) — %s\n", #expr, msg);\
        }                                                          \
        if (!ok) {                                                 \
            printf("super_assert FAIL: (%s) — %s\n", #expr, msg);  \
            if (SUPER_ASSERT_PERMISSIVE == 1)                      \
                break;                                             \
                                                                   \
            abort();                                               \
        }                                                          \
    } while(0)
#endif