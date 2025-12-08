#pragma once

#include <stdio.h>
#define HELLO_EN "Hello, World!\n"
#define HELLO_ES "Hola, Mundo!\n"
#define EN 0
#define ES 1
#ifndef LANGUAGE
#define LANGUAGE EN
#endif

const char* get_welcome_msg();