// this version doesn't split words in half

#include <stdio.h>

#define MAXLINE 1000
#define TEXTWIDTH 80

int mygetline(char s[], int lim);

int main() {
  int i, len, end;
  char line[MAXLINE];

  while ((len = mygetline(line, MAXLINE)) > 0) {
    if (len <= TEXTWIDTH) {
      printf("%s", line);
      continue;
    }
    i = 0;
    end = TEXTWIDTH;
    while (end < len) { // travels the entire line 
      if (line[end] == ' ') {
        for (; i < end; i++) { // print every character of the slice that is TEXTWIDTH long
          putchar(line[i]);
        }
        putchar('\n');
        i++;  // skip a space
        end = i + TEXTWIDTH;
      } else {
        end--;
      }
    }

    for (; i < len; i++) { // print the remaining slice 
      putchar(line[i]);
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
