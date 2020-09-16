#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void reverse(char string[], int len, char reversed[]);

int main() {
  int len, i;
  char line[MAXLINE];
  char reversed[MAXLINE];
  
  while ((len = mygetline(line, MAXLINE)) > 0) {
      line[len-1] = '\0'; // exchange '\n' for '\0', making line a string without \n at the end
      reverse(line, len-1, reversed);
      reversed[len-1] = '\n'; // append \n at the end again
      reversed[len] = '\0';
      printf("%s", reversed);
  }

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

void reverse(char string[], int len, char reversed[]) {
  int c, i, j;
  reversed[len] = '\0';
  i = 0;
  j = len - 1;
  while ((c = string[i]) != '\0') {
    reversed[j-i] = c;
    ++i;
  }
}

