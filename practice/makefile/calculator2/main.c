#include <stdio.h>
#include <unistd.h>
#include "../myadd.h"
#include "../mul.h"

int main() {
    printf("Hello, World!\n");
    printf("add! '%d'\n", add(3, 6));
    printf("mul! '%d'\n", mul(3, 6));
    return 0;
}