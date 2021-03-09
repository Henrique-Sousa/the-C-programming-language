#include <stdio.h>

int bitcount(unsigned x);

int main() {
    printf("must be 6: %d\n", bitcount(0xAA6));
    printf("must be 8: %d\n", bitcount(0x76E));
    return 0;
}

int bitcount(unsigned x) {
    int b = 0;
    do {
        b++;
    } while (x &= (x-1));
    return b;
}

