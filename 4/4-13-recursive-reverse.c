#include <stdio.h>

void reverse(char[], int, int);
void swap(char[], int, int);

int main() {
    char s[] = "I wonder how this text looks like backwards";

    reverse(s, 0, 42); 
    printf("%s\n", s);
    return 0;
}

void reverse(char s[], int start, int end) {
    if (end - start != 1 && end != start ) {
        reverse(s, start + 1, end -1); 
    }
    swap(s, start, end);
}

void swap(char s[], int i, int j) {
    char temp;

    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
