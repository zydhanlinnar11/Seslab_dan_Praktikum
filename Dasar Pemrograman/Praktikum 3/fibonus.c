#include <stdio.h>

int fibbonus(int);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fibbonus(n));
}

int fibbonus(int n) {
    if(n<=2) return 1;
    else return fibbonus(n-1) +fibbonus(n-2);
}