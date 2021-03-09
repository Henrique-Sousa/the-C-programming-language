#include <stdio.h>
#include <math.h>

int setbits(int x, int p, int n, int y);

int main() {
    int ex1 = setbits(54828, 3, 4, 2731);
    int ex2 = setbits(654, 7, 3, 1703);

    printf("assert: %s\n", ex1 == 54876 ? "true" : "false");
    printf("assert: %s\n", ex2 == 910 ? "true" : "false");

    return 0;
}

// assumes position p starts counting at 0, from right to left
// eg. the binary number 100 has 1 in position 2
int setbits(int x, int p, int n, int y) {
    int n_ones;
    n_ones = (int) (pow(2, n) - 1);
    x = x & ~(n_ones << p);
    y = y & n_ones;
    y = y << p;
    return x | y;
}

