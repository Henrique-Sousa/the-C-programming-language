#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);

int main() { 
    int len;
    char line[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0)
        printf("%s", line);
        
    return 0;
}

int mygetline(char s[], int lim) {
    int c, i;

    i = 0;
    while(i < lim - 1) {
        if ((c=getchar())==EOF) {
            break;
        }
        if (c=='\n') {
            break;
        }
        s[i] = c;
        ++i;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
