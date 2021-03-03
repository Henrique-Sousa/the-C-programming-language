#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itoa(int n, char s[]);

int main() {
    int n = 2147483647;
    int m = -2147483648;
    char s[100];
    char t[100];
    itoa(n, s);
    itoa(m, t);
    printf("%s\n", s); 
    printf("%s\n", t); 

    return 0;
}

void itoa(int n, char s[]) {
    int i, sign, tmp;
    sign = n;
    i = 0;
    do {
        tmp = ((int) n % 10);
        tmp = n >= 0 ? tmp : -tmp;
        s[i++] = tmp + '0';
    } while (((int)(n /= 10)) >= 0 ? n > 0 : n < 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
