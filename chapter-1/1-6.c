#include <stdio.h>

main() {
  int c;
  
  while (1) {
    c = getchar();
    getchar();
    printf("%d\n", c != EOF);
    if (c == EOF) {
      break;
    }
  }
      
}
