#include <stdio.h>
 
int main() {
    int x, y, i,s;
    unsigned long long max=0, a[100][100];
    scanf("%d %d", &y, &x);
    for(i=0; i<x; i++) {
        int j;
        for(j=0; j<y; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d", &s);
    for(i=0; i<=x-s; i++) {
        int j;
        for(j=0; j<=y-s; j++) {
            int k;
            unsigned long long max1=0;
            for(k=i; k<s+i; k++) {
                int l;
                for(l=j; l<s+j; l++) {
                    max1 += a[k][l];
                    //printf("a[%d][%d]\n", k, l);
                }
            }
            //puts("");
            if(max1 > max) max = max1;
        }
    }
    printf("%llu\n", max);
    return 0;
}