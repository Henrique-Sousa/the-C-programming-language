#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char name[] = "He;ll*o: W!o;rl*d*!:!";
    char forbidden[] = ";:!*";
    printf("original: %s\n", name);
    squeeze(name, forbidden);
    printf("squeezed: %s\n", name);

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j, k, found;
    
    found = 0;
    for(i = j = 0; s1[i] != '\0'; i++) {
        for(k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            s1[j] = s1[i];
            j++;
        } else {
            found = 0;
        }
    }
    s1[j] = '\0';
}

