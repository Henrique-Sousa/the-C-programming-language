#include <stdio.h>
#include "strrindex.h"

int main() {
    char* txt;
    char* expr;
    int result;

    txt = "this is string example....wow!!!";
    expr = "is";
    result = strrindex(txt, expr);
    printf("must be 5: %d\n", result);
    
    txt = "Mi casa, su casa.";
    expr = "casa";
    result = strrindex(txt, expr);
    printf("must be 12: %d\n", result);

    txt = "Mi casa, su casa.";
    expr = "kasa";
    result = strrindex(txt, expr);
    printf("must be -1: %d\n", result);

    return 0;
}
