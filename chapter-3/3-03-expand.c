#include <stdio.h>

void expand(char* s1, char* s2);

int main() {
    char* range = "a-z0-9";
    char result[100];
    expand(range, result);
    printf("%s\n", result);
    
    return 0;
}

// handle the simplest cases like a-z, N-P, 3-8
void expand(char* s1, char* s2) {
    char letter, end, s2p;
    int i, j;

    j = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i+1] == '-') {
            for (letter = s1[i], end = s1[i+2]; letter <= end; j++, letter++) {
                s2[j] = letter; 
            }
            i+=2;
        }
    }

    s2[j] = '\0';
}
