#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itoa(int n, char s[]);

int main() {
    int n = 2147483647;
    int m = -2147483648;
    char s[11];
    char t[11];
    itoa(n, s);
    itoa(m, t);
    printf("%s\n", s); 
    printf("%s\n", t); 

    return 0;
}

void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0) {
        if (n == INT_MIN) {
            n = -(n + 1);
            s[0] = ((n % 10) + 1) + '0';
        } else {
            n = -n;
            s[0] = n % 10 + '0';
        }
        n /= 10;
        i = 1;
    } else {
        i = 0;
    }
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
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
