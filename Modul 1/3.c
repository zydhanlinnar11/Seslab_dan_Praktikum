#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    for(i=2; i<=n; i++) {
        int j, prime = 1;
        for(j=2; j*j<=i; j++) {
            if(i % j == 0) {
                prime = 0;
                break;
            }
        }
        if(prime)
            putchar('*');
        else
            printf("%d", i);
        if(i < n) putchar(' ');
    }
    putchar('\n');
    return 0;
}