#include <stdio.h>
#include <string.h>

void mystrcat(char*, char*);

int main() {
    char s[20];
    strcpy(s, "hello");
    char* t = " world";
    mystrcat(s, t);
    printf("%s\n", s);
    return 0;
}

void mystrcat(char* s, char* t) {
    while (*s != '\0') {
        s++;
    }
    while ((*s++ = *t++) != 0) {
        ;
    }
}
