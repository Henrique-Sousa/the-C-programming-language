#include <stdio.h>
#define swap(t, x, y) \
    t temp; \
    temp = x; \
    x = y; \
    y = temp;

int main() {
    int x = 1;
    int y = 2;

    printf("%d and %d\n", x, y);
    swap(int, x, y);
    printf("%d and %d\n", x, y);
    
    return 0;
}
