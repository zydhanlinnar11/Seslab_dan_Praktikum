#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    printf("%s\n", (a & 1) ? "Ganjil" : "Genap");
    return 0;
}