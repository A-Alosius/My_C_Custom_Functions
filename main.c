/**
You can test the functions here
 */

#include <stdio.h>

#include "my_libc.h"

int main(void) {
    char text[] = "\t ";
    printf("str_to_int: %d\n", str_to_int(text));
    return 0;
}