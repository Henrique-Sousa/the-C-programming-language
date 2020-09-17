#include <stdio.h>

int main() {

  int c, singlequoted, doublequoted, escaped, slashed, commented, asterisk;
  
  escaped = doublequoted = singlequoted = slashed = commented = asterisk = 0;

  while ((c = getchar()) != EOF) {
    if (commented) {
      if (asterisk) {
        if (c == '/') {
          asterisk = 0;
          commented = 0;
        }
      } else {
        if (c == '*') {
          asterisk = 1;
        }
      }
    } else {
      if (doublequoted) {
        if (escaped) {
          escaped = 0;
        } else {
          if (c == '\"') {
            doublequoted = 0;
          }
          if (c == '\\') {
            escaped = 1;
          }    
        } 
      } else {
        if (singlequoted) {
          if (c == '\'') {
            singlequoted = 0;
          }
        } else {
          if (slashed) {
            if (c == '*') {
              slashed = 0;
              commented = 1;
              continue;
            }
          } else if (c == '/') {
            slashed = 1;
            continue;
          }
          if (c == '\'') {
            singlequoted = 1;
          }
          if (c == '\"') {
            doublequoted = 1;
          }
        }
      }
      putchar(c);
    } 
   
  }

  return 0;
}
