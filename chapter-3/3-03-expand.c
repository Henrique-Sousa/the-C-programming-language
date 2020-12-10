#include <stdio.h>

void expand(char* s1, char* s2);

int main() {
    char* range = "f-r";
    char result[100];
    expand(range, result);
    printf("%s\n", result);
    
    return 0;
}

// handle the simplest cases like a-z, N-P, 3-8
void expand(char* s1, char* s2) {
    char letter;
    int i;

    for (i = 0, letter = s1[0]; letter <= s1[2]; letter++, i++) {
        s2[i] = letter; 
    }
    s2[i] = '\0';
}
