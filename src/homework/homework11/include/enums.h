#ifndef ENUMS_H
#define ENUMS_H

typedef enum {
    MACCES, // permission denied
    MNOMEM, // no memory
    MINVAL, // invalid argument
} ErrorCode;

const char* getErrorMessage(ErrorCode error);


#endif // ENUMS_H