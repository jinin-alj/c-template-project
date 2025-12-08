#include <stdio.h>
#include "enums.h"

const char* getErrorMessage(ErrorCode error) {
    switch (error) {
        case MACCES:
            return "Permission denied";
        case MNOMEM:
            return "No memory available";
        case MINVAL:
            return "Invalid argument";
        default:
            return "Unknown error";
    }
}
