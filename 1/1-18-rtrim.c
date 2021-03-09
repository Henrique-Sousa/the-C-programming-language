#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void rtrim(char line[], int len, char dest[]);

int main() {
  int len, i;
  char line[MAXLINE];
  char result_line[MAXLINE];

  while ((len = mygetline(line, MAXLINE)) > 0) {
    if (len > 1) {
      rtrim(line, len, result_line);
      printf("%s", result_line);
    }
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

void rtrim(char line[], int len, char dest[]) {
  int i;

  if (len == 1) return;

  // set i to be the last non space character
  i = len-2;  // need to start in len-2 because line[len] == '\0' and line[len-1] == '\n'
  while ((line[i] == ' ' || line[i] == '\t') && i >= 0) {
    --i; 
  }
  
  dest[i+2] = '\0';
  dest[i+1] = '\n';
  while (i >= 0) {
    dest[i] = line[i];
    --i;
  }
}

