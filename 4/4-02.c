#include <stdio.h>
#include "cientific_atof.h"

int main() {
    float x, y;
    // tests
    x = cientific_atof("123.456e+3");
    y = 123.456e+3;
    printf("%d\n", x == y);
    x = cientific_atof("123.456e3");
    y = 123.456e3;
    printf("%d\n", x == y);
    x = cientific_atof("123.456e-2");
    y = 123.456e-2;
    printf("%d\n", x == y);
    x = cientific_atof("1.2345e+10");
    y = 12345000000.0; 
    printf("%d\n", x == y);
}
