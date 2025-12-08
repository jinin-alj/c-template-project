#include <stdio.h>

typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR
} LogLevel;

typedef void (*Logger) (const char *message, LogLevel level);

void logMessage(const char *message, LogLevel level);

void performTask(Logger logger){
    logger("Task started", INFO);

    logger("Be careful you literally have no memory", WARNING);
    
    logger("Task failed due to error", ERROR);
}

void consoleLogger(const char *message, LogLevel level){
    printf("[%d] %s\n", level, message);
}

void fileLogger(const char *message, LogLevel level){
    FILE *file = fopen("log.txt", "a");
    fprintf(file, "[%d] %s\n", level, message);
    fclose(file);
}

int main(){

    performTask(consoleLogger);
    performTask(fileLogger);

    return 0;
}