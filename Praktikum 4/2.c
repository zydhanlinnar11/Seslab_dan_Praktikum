#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct agen {
    char a[101];
    int d;
    int m;
    int y;
};

typedef struct agen Agent;

unsigned int date[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unsigned int datekbs[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Agent *orang;

bool validOrNot(int, int, int);

int main() {
    int t, i;
    scanf("%d", &t);
    orang = (Agent *) malloc(t*sizeof(Agent));
    for (i=0; i<t; i++) {
        getchar();
        gets(orang[i].a);
        scanf("%d%*c%d%*c%d", &orang[i].d, &orang[i].m, &orang[i].y);
    }
    for(i=0; i<t; i++) {
        bool valid = validOrNot(orang[i].d, orang[i].m, orang[i].y);
        printf("Orang ke : %d\n", i+1);
        if (valid) {
            printf("Nama: %s\n", orang[i].a);
            printf("TL  : %d-%d-%d\n", orang[i].d, orang[i].m, orang[i].y);
            printf("Umur: %d\n", 2019-orang[i].y);
        } else {
            puts("Nama: Kosong\nTL  : 1-1-1\nSepertinya ada kesalahan");
        }
    }
    return 0;
}

bool validOrNot(int d, int m, int y) {
    if(y < 0 || y >= 2019) return false;
    if(m < 1 || m > 12) return false;
    if(d < 0 || ((y % 4 == 0) ? (d > datekbs[m]) : (d > date[m]))) return false;
    return true;
}
