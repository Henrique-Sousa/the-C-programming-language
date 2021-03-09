#include "strrindex.h"
#include "strsize.h"
#include <stdio.h>

int strrindex(char* s, char* t) {
    int i, j, k;

    i = strsize(s) - 1;
    k = strsize(t) - 1;
    while (i >= 0) {
        if (s[i] == t[k]) {
            j = k; 
            while (j >= 0 && s[i] == t[j]) {
                j--;
                i--;
            }
            if (j == -1) {
                return i+1;
             }
        }
        i--;
    }
    return -1;
}
