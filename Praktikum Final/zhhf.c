#include <stdio.h>

int main() {
    int i, t;
    int sudah[501000];
    scanf("%d", &t);
    for(i=0; i<t; i++) {
        int n, m, j;
        scanf("%d %d", &n, &m);
        int angka=1, currlow = 1;
        int yangpernah = 0, currlowcheck=0;
        sudah[0] = 0;
        for(j=1; j<=n; j++) {
            if(j % 2 == 1) {
                if(j>1) currlow++;
                if(sudah[currlowcheck]==currlow) {
                    currlow++;
                    currlowcheck++;
                }
                angka = currlow;
            } else {
                // printf("Yang pernah: %d\n", currlow);
                angka = currlow*m;
                sudah[yangpernah] = angka;
                yangpernah++;
            }
            if(j==n)printf("%s : %d\n",((j/2) % 2 == 0) ? "Hana" : "Hinata", angka);
        }
    }
    return 0;
}