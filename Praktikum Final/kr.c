#include <stdio.h>
#include <stdbool.h>

int h;
int minindex[31][31] = {0};

int minval(int a[31][31], int depth, int horizontal) {
    if(depth==h-1) {
        return a[depth][horizontal];
    } else {
        int min1 = minval(a, depth+1, horizontal);
        int min2 = minval(a, depth+1, horizontal+1);
        minindex[depth][horizontal] = (min1 >= min2) ? a[depth][horizontal]+min2:a[depth][horizontal]+min1;
        return (min1 >= min2) ? a[depth][horizontal]+min2:a[depth][horizontal]+min1;
    }
}

void changemin(int a[31][31], int depth, int horizontal) {
    if(h==1) {
        a[0][0] = -1;
        return;
    }
    if(depth==0) {
        a[depth][horizontal] = -1;
    }
    // if(depth==h-2) {
    //     if(minindex[depth+1][horizontal] < minindex[depth+1][horizontal+1])
    //         a[depth+1][horizontal] = -1;
    //     else if(minindex[depth+1][horizontal] > minindex[depth+1][horizontal+1])
    //         a[depth+1][horizontal+1] = -1;
    //     else {
    //         a[depth+1][horizontal+1] = -1;
    //         a[depth+1][horizontal] = -1;
    //     }
    //     return;
    // }
    if(a[depth][horizontal]==-1) {
        if(minindex[depth+1][horizontal] < minindex[depth+1][horizontal+1])
            a[depth+1][horizontal] = -1;
        else if(minindex[depth+1][horizontal] > minindex[depth+1][horizontal+1])
            a[depth+1][horizontal+1] = -1;
        else {
            a[depth+1][horizontal+1] = -1;
            a[depth+1][horizontal] = -1;
        }
        if(depth==h-2) return;
        changemin(a, depth+1, horizontal);
        changemin(a, depth+1, horizontal+1);
    } else return;
}

int main() {
    minindex[0][0] = 1;
    int i, a[31][31];
    scanf("%d", &h);
    for(i=0; i<h; i++) {
        int j;
        for(j=0; j<=i; j++) {
            scanf("%d", &a[i][j]);
            minindex[i][j] = a[i][j];
        }
    }
    minval(a, 0, 0);
    changemin(a, 0, 0);
    int lasthorizontal;
    for(i=0; i<h; i++) {
        int j;
        bool sudah = false;
        for(j=0; j<=i; j++) {
            printf("%d", a[i][j]);
            if(j<i) printf(" ");
        }
        printf("\n");
    }
    return 0;
}