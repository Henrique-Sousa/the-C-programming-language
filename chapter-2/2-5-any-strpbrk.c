#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    char s1[] = "Helloworld";
    char s2[] = "Blank";
    char s3[] = "abcde2fghi3jk4l";
    char s4[] = "34";
    char s5[] = "app";
    char s6[] = "kite";
    printf("must be 2: %d\n", any(s1, s2));
    printf("must be 10: %d\n", any(s3, s4));
    printf("must be -1: %d\n", any(s5, s6));

    return 0;
}


int any(char s1[], char s2[]) {
    int i, j;

    for(i = 0; s1[i] != '\0'; i++) {
        for(j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}
