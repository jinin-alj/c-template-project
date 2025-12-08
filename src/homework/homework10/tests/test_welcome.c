#include "utest.h"
#include "welcome.h"

UTEST(english, welcome_message) {
  const char *msg = get_welcome_msg();
  ASSERT_STREQ(HELLO_EN, msg);
}

UTEST(spanish, welcome_message) {
  const char *msg = get_welcome_msg();
  ASSERT_STREQ(HELLO_ES, msg);
}

UTEST_MAIN();
