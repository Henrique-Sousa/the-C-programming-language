#include <stdio.h>

int main() {

    int c, singlequoted, doublequoted, escaped, slashed, onelinecommented, multilinecommented, asterisk;
    
    escaped = doublequoted = singlequoted = slashed = onelinecommented = multilinecommented = asterisk = 0;

    while ((c = getchar()) != EOF) {
        
        if (onelinecommented) {
            if (c == '\n') {
                onelinecommented = 0;
                putchar('\n');
            }
        } else if (multilinecommented) {
            if (asterisk) {
                if (c == '/') {
                    asterisk = 0;
                    multilinecommented = 0;
                }
            } else if (c == '*') {
                asterisk = 1;
            }
        } else if (doublequoted) {
            if (escaped) {
                escaped = 0;
            } else {
                if (c == '\"') {
                    doublequoted = 0;
                }
                if (c == '\\') {
                    escaped = 1;
                }        
            } 
            putchar(c);
        } else if (singlequoted) {
            if (escaped) {
                escaped = 0;
            } else {
                if (c == '\'') {
                    singlequoted = 0;
                }
                if (c == '\\') {
                    escaped = 1;
                }
            }
            putchar(c);
        } else if (c == '\"') {
            doublequoted = 1;
            putchar(c);
        } else if (c == '\'') {
            singlequoted = 1;
            putchar(c);
        } else if (slashed) {
            if (c == '*') {
                slashed = 0;
                multilinecommented = 1;
            } else if (c == '/') {
                slashed = 0;
                onelinecommented = 1;
            } else {
                putchar('/');
                putchar(c);
                slashed = 0;
            }
        } else if (c == '/') {
            slashed = 1;
        } else {
            putchar(c);
        }

    }

    return 0;
}
