#include <stdio.h>
#include <math.h>

void toh(unsigned short, char, char, char);

int main() {
    unsigned short t, i;
    scanf("%hu", &t);

    for(i=1; i<=t; i++) {
        unsigned short n;
        scanf("%hu", &n);

        printf("Kasus %hu:\n", i);
        toh(n, 'A', 'B', 'C');
        printf("%hu langkah\n", (unsigned short)pow(2, n)-1);
    }
}

void toh(unsigned short n, char source, char aux, char dest) { 
    if (n==1) {
        printf("Pindah piringan 1 dari pasak %c ke pasak %c\n", source, dest);
    } else {
        toh(n-1, source, dest, aux);
        printf("Pindah piringan %hu dari pasak %c ke pasak %c\n", n, source, dest);
        toh(n-1, aux, source, dest);
    }
}