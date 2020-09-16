#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void reverse(char string[], int len, char reversed[]);

int main() {
  /*int len;*/
  /*char line[MAXLINE];*/
  
  char rev[12]; 
  char line[] = "Hello world";
  reverse(line, 11, rev);
  printf("%s\n", rev);
  
  /*while ((len = mygetline(line, MAXLINE)) > 0)*/
      /*printf("%s", line);*/
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

