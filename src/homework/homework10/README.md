Files

welcome.h contains the message constants and the function declaration.

welcome.c implements get_welcome_msg() using preprocessor directives.

main.c contains the main function

hello.c is due to me following a step by step process to make main.c

test_welcome.c unit tests that check the English and Spanish versions.

How it works

If compiled with -DENGLISH, the function returns the English message.

If compiled with -DSPANISH, it returns the Spanish message.

If neither is defined, it defaults to English.

