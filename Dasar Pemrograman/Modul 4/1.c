#include <stdio.h>

void tukar(int *, int *);

int main() {
    int a, b;
    printf("Input two integers: ");
    scanf("%d %d", &a, &b);
    printf("Before swapping - > a : %d, b : %d\n", a,b);
    tukar(&a, &b);
    printf("After swapping  - > a : %d, b : %d\n", a,b);

    return 0;
}

void tukar(int * a, int * b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
};