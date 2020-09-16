#include <stdio.h>
#define tabstop 4

int main() {
  int i, c, origspaces, newspaces, numtabs;
  
  origspaces = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++origspaces;
    } else if (origspaces > 0) {
      numtabs = origspaces / tabstop;
      newspaces = origspaces % tabstop;
      for (i=0; i<numtabs; i++) {
        putchar('\t');
      }
      for (i=0; i<newspaces; i++) {
        putchar(' ');
      }
      putchar(c);
      origspaces = 0;
    } else {
      putchar(c);
    }
  }
}
