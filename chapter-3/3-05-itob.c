#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void itob(int n, char s[], unsigned int b);

int main() {
    char s[100];
    char t[100];
    itob(534536, s, 8);
    itob(436746, t, 16);
    printf("%s\n", s);
    printf("%s\n", t);
    return 0;
}

void itob(int n, char s[], unsigned int b) {
    int i, sign, tmp;
    if (b > 10 && b != 16) {
        b = 10;
    }
    sign = n;
    i = 0;
    do {
        tmp = ((int) n % b);
        tmp = n >= 0 ? tmp : -tmp;
        if (b == 16 && tmp > 9 && tmp < 16) {
           tmp += 7;
        }
        s[i++] = tmp + '0';
    } while (((int)(n /= b)) >= 0 ? n > 0 : n < 0);
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
