#include <stdio.h>

void expand(char* s1, char* s2);

int main() {
    char* range1 = "a-zA-Z0-9";
    char* range2 = "a-f-z";
    char* range3 = "-a-jbn-q-";
    char result1[100];
    char result2[100];
    char result3[100];
    expand(range1, result1);
    expand(range2, result2);
    expand(range3, result3);
    printf("%s\n", result1);
    printf("%s\n", result2);
    printf("%s\n", result3);
    
    return 0;
}

// handle the simplest cases like a-z, N-P, 3-8
void expand(char* s1, char* s2) {
    char letter, end, s2p;
    int i, j;

    j = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-') {
            s2[j] = '-';
            j++;
        }
        else if (s1[i+1] == '-' && s1[i+2] != '\0') {
            for (letter = s1[i], end = s1[i+2]; letter <= end; j++, letter++) {
                s2[j] = letter; 
            }
            i+=2;
        }
        else {
            s2[j] = s1[i];
            j++;
        }
    }

    s2[j] = '\0';
}
