#include <stdio.h>
#include <string.h>

int strend(char*, char*);

int main() {
    printf("%d\n", strend("hello world", "world"));
    printf("%d\n", strend("hello world", "abcde"));
    printf("%d\n", strend("foo bar baz", "bar"));

    return 0;
}

int strend(char* s, char* t) {
    char* start = s + (strlen(s)-strlen(t));
    while (*t != '\0') {
        if (*start != *t) {
            return 0;
        }
        start++;
        t++;
    }
    return 1;

}
