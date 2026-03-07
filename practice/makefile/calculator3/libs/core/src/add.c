#include "core.h"
#include "utils.h"

int add(int a, int b)
{
    return (a + b);
}
int    add_and_print(int a, int b)
{
    say_bye();
    return add(a, b); 
}
