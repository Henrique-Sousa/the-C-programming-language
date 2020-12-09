#include <stdio.h>

void escape(char* s, char* t);
void unescape(char* s, char* t);

int main() {
    char* s = "first sentence\nsecond sentence\n\tindented sentence";
    char t[100];
    char r[100];
    printf("unescaped:\n%s\n", s);
    escape(s, t);
    printf("\nescaped:\n%s\n", t);
    unescape(t, r);
    printf("\nescaped again:\n%s\n", r);
    return 0;
}

void escape(char* s, char* t) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case '\n':
                t[j] = '\\';
                t[j+1] = 'n';
                j += 2;
                break;
            case '\t':
                t[j] = '\\';
                t[j+1] = 't';
                j += 2;
                break;
            default:
                t[j] = s[i];
                j++;
                break;
        }
    }
    t[j] = '\0';
}

void unescape(char* s, char* t) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] == '\\') {
            i ++;
            switch(s[i]) {
                case 'n':
                    t[j] = '\n';
                    j++;
                    break;
                case 't':
                    t[j] = '\t';
                    j++;
                    break;
            }
        } else {
            t[j] = s[i];
            j++;
        }
    }
    t[j] = '\0';
}
