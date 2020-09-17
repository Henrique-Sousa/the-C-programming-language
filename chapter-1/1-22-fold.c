#include <stdio.h>

#define MAXLINE 1000
#define TEXTWIDTH 80

int mygetline(char s[], int lim);

int main() {
  int nparts, i, j, len;
  char line[MAXLINE];

  while ((len = mygetline(line, MAXLINE)) > 0) {
    if (len <= TEXTWIDTH) {
      printf("%s", line);
      continue;
    }
    nparts = (len / TEXTWIDTH) + 1;
    for (i = 0; i < nparts; i++) {
      for (j = i*TEXTWIDTH; j < TEXTWIDTH*(i+1); j++) {
        putchar(line[j]);
      }
      putchar('\n');
    }

  }

  return 0;
}

int mygetline(char s[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = (char) c;
  if (c == '\n') {
    s[i] = (char) c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
