#include <stdio.h>
#define MAXLINE 1000
#define OUT 0
#define IN 1

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

  i = len-2;
  if (line[len-2] == ' ' || line[len-2] == '\t') {
    i = len-3;
    while ((line[i] == ' ' || line[i] == '\t') && i >= 0) {
      --i; 
    }
  }
  dest[i+2] = '\0';
  dest[i+1] = '\n';
  while (i >= 0) {
    dest[i] = line[i];
    --i;
  }
}

