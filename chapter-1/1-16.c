#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main() { int len;
  char line[MAXLINE];

  while ((len = mygetline(line, MAXLINE)) > 0)
    printf("%d\n", len);
    
  return 0;
}

int mygetline(char s[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
