#include <stdio.h>

int main() {
  int c, inslash, incomment, inasterisk;
  
  inslash = incomment = inasterisk = 0;

  while ((c = getchar()) != EOF) {
    if (incomment == 0) {
      if (inslash == 1) {
        if (c == '*') {
          inslash = 0;
          incomment = 1;
          continue;
        }
      } else if (c == '/') {
        inslash = 1;
        continue;
      }
      putchar(c);
    } else {
      if (inasterisk == 0) {
        if (c == '*') {
          inasterisk = 1;
        }
      } else if (c == '/') {
        inasterisk = 0;
        incomment = 0;
      }
    }
   
  }

  return 0;
}
