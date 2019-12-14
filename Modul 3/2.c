#include <stdio.h>

int pola(int n) {
    if(n==1) return 1;
    else return (n*n)+pola(n-1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", pola(n));
    return 0;
}