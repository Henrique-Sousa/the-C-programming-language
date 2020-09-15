#include <stdio.h>

main() {
  int c, s;

  s = 0;
  while((c = getchar()) != EOF)
    if(c == '\n' || c == '\t' || c == ' ')
      ++s;
    printf("%d\n", s);
}
