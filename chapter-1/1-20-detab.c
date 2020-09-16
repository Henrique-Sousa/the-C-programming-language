#include <stdio.h>
#define tabstop 2

int main() {
  int c, i;
  while ((c=getchar()) != EOF) {
    if (c == '\t') {
      for (i=0; i<tabstop; i++) {
        putchar(' ');
      }
    } else {
      putchar(c);
    }
  }
}
