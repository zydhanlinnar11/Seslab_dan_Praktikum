#include <stdio.h>
#include <stdlib.h>

struct account {
    int ID;
    int saldo;
    char name[1001];
};

typedef struct account acc;

acc * bank;

int main() {
    int p, i;
    scanf("%d", &p);
    bank = (acc *) malloc(p * sizeof(acc));
    for (i=0; i<p; i++) {
        scanf("%d", &bank[i].ID);
        getchar();
        gets(bank[i].name);
        bank[i].saldo = 100;
    }
    while (1) {
        int option;
        scanf("%d", &option);
        if(option == 1) {
            int ID, num;
            scanf("%d %d", &ID, &num);
            bank[ID-1].saldo += (bank[ID-1].saldo + num > 1000) ? num+20 : num;
        } else if(option == 2) {
            int ID, num;
            scanf("%d %d", &ID, &num);
            bank[ID-1].saldo -= (bank[ID-1].saldo < num) ? bank[ID-1].saldo : num;
        } else break;
    }
    for (i=0; i<p; i++) {
        printf("Akun %d\n%s\n%.2f\n", i+1, bank[i].name, (float)bank[i].saldo);
    }
    return 0;
}