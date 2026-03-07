#include <stdio.h>
#include <unistd.h>
#include "core.h"
#include "utils.h"

int main() {
    say_hello();
    printf("sub! '%d'\n", sub(3, 6));
    add_and_print(3, 9);
    return 0;
}