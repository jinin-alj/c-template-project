#include <stdio.h>
#include "enums.h"

int main() {
    ErrorCode error = MNOMEM;
    printf("Error: %s\n", getErrorMessage(error));
    return 0;
}

// answer to the questions in the exercise:
// 1
// You do not need to handle invalid error codes in your getErrorMessage function. Why?
// Because ErrorCode is an enum, and the function handles all the defined enum values, any value outside of what I defined is invalid anyway. 
// 2
// Can you explain why, despite strerror returning a char *, we do not need to free the returned string?
// Because the strings returned by strerror() are statically allocated by the C standard library. They should not be freed by the caller.