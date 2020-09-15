#include <stdio.h>

main() {
  int c, last_was_blank;

  last_was_blank = 0;
  while((c = getchar()) != EOF)
    if(last_was_blank == 0) {
      putchar(c);
      if (c == ' ')
        last_was_blank = 1;
      else 
        last_was_blank = 0;
    } else if (c != ' ') {
      putchar(c);
      last_was_blank = 0;
    } 
}
