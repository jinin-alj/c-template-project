#include <stdio.h>
#include "super_assert.h"

int main() {
    int x = 5;

    super_assert(x == 5, "x should be 5");
    super_assert(x != 5, "x should not be 5");

    return 0;
}
