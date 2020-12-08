#include <stdio.h>

int lower(int c);

int main() {
    printf("%c\n", lower('X'));
    printf("%c\n", lower('T'));
    printf("%c\n", lower('s'));
    
    return 0;
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
