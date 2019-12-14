#include <stdio.h>

int main() {
    int i, n;
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        if(i & 1)
            printf("%d", i);
        else
            putchar('*');
        if(i < n) putchar(' ');
    }
    putchar('\n');
    return 0;
}