#include "strsize.h"

int strsize(char* s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    return n;
}

