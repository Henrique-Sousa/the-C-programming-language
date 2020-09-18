#include <stdio.h>
#define MAXSTACKSIZE 1000

char stack[MAXSTACKSIZE];
int p;

char peek();
void pop();
void push(char c);

int main() {

    int c, singlequoted, doublequoted, escaped, slashed, commented, asterisk;
    
    escaped = doublequoted = singlequoted = slashed = commented = asterisk = 0;
    p = -1;

    while ((c = getchar()) != EOF) {
        if (commented) {
            if (asterisk) {
                if (c == '/') {
                    asterisk = 0;
                    commented = 0;
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
        } else if (c == '\"') {
            doublequoted = 1;
        } else if (c == '\'') {
            singlequoted = 1;
        } else if (slashed) {
            if (c == '*') {
                slashed = 0;
                commented = 1;
            } else {
                slashed = 0;
            }
        } else if (c == '/') {
            slashed = 1;
        } else {
            if (c == '(' || c == '[' || c == '{') {
                push((char) c);
            }
            if (c == ')') {
                if (peek() == '\0') {
                    printf(") without (\n");
                    return 1;
                } else if (peek() == '[') {
                    printf("[)\n");
                    return 1;
                } else if (peek() == '{') {
                    printf("{)\n");
                    return 1;
                } else if (peek() == '(') {
                    pop();
                }
            }
            if (c == ']') {
                if (peek() == '\0') {
                    printf("] without [\n");
                    return 1;
                } else if (peek() == '(') {
                    printf("(]\n");
                    return 1;
                } else if (peek() == '{') {
                    printf("{]\n");
                    return 1;
                } else if (peek() == '[') {
                    pop();
                }
            }
            if (c == '}') {
                if (peek() == '\0') {
                    printf("} without {\n");
                    return 1;
                } else if (peek() == '(') {
                    printf("(}\n");
                    return 1;
                } else if (peek() == '[') {
                    printf("[}\n");
                    return 1;
                } else if (peek() == '{') {
                    pop();
                }
            }
        }

    }
    if (peek() != '\0') {
        printf("%c not closed\n", peek());
    }
    return 0;
}

char peek() {
    if (p >= 0) {
        return stack[p];
    } else {
        return '\0';
    }
}

void pop() {
    if (p >= 0) {
        --p;
    }
}

void push(char c) {
    ++p;
    stack[p] = c;
}

