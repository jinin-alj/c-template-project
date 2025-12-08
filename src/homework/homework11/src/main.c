#include <stdio.h>
#include "enums.h"

int main() {
    ErrorCode error = MNOMEM;
    printf("Error: %s\n", getErrorMessage(error));
    return 0;
}
