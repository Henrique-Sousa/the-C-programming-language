#include <stdio.h>
#define MAXSTACKSIZE 1000

char stack[MAXSTACKSIZE];
int p;

int line, col, stackline, stackcol;

char peek();
void pop();
void push(char c);
void printlinecol();
void printstacklinecol();

int main() {

    int c, singlequoted, doublequoted, escaped, slashed, onelinecommented, multilinecommented, asterisk;

    escaped = doublequoted = singlequoted = slashed = onelinecommented = multilinecommented = asterisk = 0;
    p = -1;

    line = 1;
    col = 0;

    stackline = stackcol = -1;

    while ((c = getchar()) != EOF) {
        ++col;
        if (c == '\n') {
            ++line;
            col = 0;
        }

        if (onelinecommented) {
            if (c == '\n') {
                onelinecommented = 0;
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
                multilinecommented = 1;
            } else if (c == '/') {
                slashed = 0;
                onelinecommented = 1;
            } else {
                slashed = 0;
            }
        } else if (c == '/') {
            slashed = 1;
        } else {
            if (c == '(' || c == '[' || c == '{') {
                push((char) c);
                stackline = line;
                stackcol = col;
            }
            if (c == ')') {
                if (peek() == '\0') {
                    printf(") without (\n");
                    printstacklinecol();
                    printlinecol();
                    return 1;
                } else if (peek() == '[') {
                    printf("[)\n");
                    printstacklinecol();
                    printlinecol();
                    return 1;
                } else if (peek() == '{') {
                    printf("{)\n");
                    printstacklinecol();
                    printlinecol();
                    return 1;
                } else if (peek() == '(') {
                    pop();
                }
            }
            if (c == ']') {
                if (peek() == '\0') {
                    printf("] without [\n");
                    printstacklinecol();
                    printlinecol();
                    return 1;
                } else if (peek() == '(') {
                    printf("(]\n");
                    printstacklinecol();
                    printlinecol();
                    return 1;
                } else if (peek() == '{') {
                    printf("{]\n");
                    printstacklinecol();
                    printlinecol();
                    return 1;
                } else if (peek() == '[') {
                    pop();
                }
            }
            if (c == '}') {
                if (peek() == '\0') {
                    printf("} without {\n");
                    printstacklinecol();
                    printlinecol();
                    return 1;
                } else if (peek() == '(') {
                    printf("(}\n");
                    printstacklinecol();
                    printlinecol();
                    return 1;
                } else if (peek() == '[') {
                    printf("[}\n");
                    printstacklinecol();
                    printlinecol();
                    return 1;
                } else if (peek() == '{') {
                    pop();
                }
            }
        }

    }
    if (peek() != '\0') {
        printf("%c not closed\n", peek());
        printf("at line %d, column %d\n", stackline, stackcol);
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

void printlinecol() {
    printf("at line %d, column %d\n", line, col);
}
void printstacklinecol() {
    printf("at line %d, column %d\n", stackline, stackcol);
}
