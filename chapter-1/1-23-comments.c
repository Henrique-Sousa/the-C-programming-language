#include <stdio.h>

int main() {
  int c, inquote, indoublequote, inbackslash, inslash, incomment, inasterisk;
  
  inbackslash = indoublequote = inquote = inslash = incomment = inasterisk = 0;

  while ((c = getchar()) != EOF) {
    if (incomment == 0) {
      if (indoublequote == 0) {
        if (inquote == 0) {
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
          if (c == '\'') {
            inquote = 1;
          }
          if (c == '\"') {
            indoublequote = 1;
          }
        } else if (c == '\'') {
          inquote = 0;
        }
      } else if (inbackslash == 0) {
        if (c == '\"') {
          indoublequote = 0;
        }
        if (c == '\\') {
          inbackslash = 1;
        }    
      } else {
        inbackslash = 0;
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
