#include "welcome.h"

const char* get_welcome_msg() {
# if LANGUAGE == EN
   printf(HELLO_EN);
# elif LANGUAGE == ES
   printf(HELLO_ES);
# else
    printf("error: no language defined\n");
    return 1;
# endif
   return 0;
}

