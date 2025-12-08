#include <stdio.h>
#include "welcome.h"

int main() {
    const char *msg = get_welcome_msg();
    printf("%s", msg);
    return 0;
}

