#include <stdio.h>
#include <stdbool.h>
#define ull unsigned long long
 
int main() {
    short i, t;
    scanf("%hd", &t);
    for(i=1; i<=t; i++) {
        int j, n, arr[100000];
        scanf("%d", &n);
        for(j=0; j<n; j++) {
            int atemp;
            scanf("%d", &atemp);
            if(j==0) arr[0] = atemp;
            else arr[j] = arr[j-1] + atemp;
        }
        int a, b, x, y;
        scanf("%d %d", &x, &a);
        scanf("%d %d", &y, &b);
        int atmp = a, btmp = b;
        if(btmp > atmp) {
            atmp ^= btmp;
            btmp ^= atmp;
            atmp ^= btmp;
        }
        while(atmp % btmp != 0) {
            int tmp = atmp;
            atmp = btmp;
            btmp = tmp % btmp;
        }
        int kpk = (a * b) / btmp;
        ull k;
        scanf("%llu", &k);
        bool bisa = false;
        for(j=1; j<=n; j++) {
            int nkpk = j / kpk, na = (j / a) - nkpk, nb = (j / b) - nkpk;
            if (nkpk == 0 && na == 0 && nb == 0) continue;
            ull sum1 = ((arr[n-1] - ((n-nkpk-1 >= 0) ? arr[n-nkpk-1] : 0)) * (x + y) / 100)
            + ((((n-nkpk-1 >= 0) ? arr[n-nkpk-1] : 0) - ((n-nkpk-na-1 >= 0) ? arr[n-nkpk-na-1] : 0)) * x / 100)
            + ((((n-nkpk-na-1 >= 0) ? arr[n-nkpk-na-1] : 0) - ((n-nkpk-na-nb-1 >= 0) ? arr[n-nkpk-na-nb-1] : 0)) * y / 100);
            ull sum2 = ((arr[n-1] - ((n-nkpk-1 >= 0) ? arr[n-nkpk-1] : 0)) * (x + y) / 100)
            + ((((n-nkpk-1 >= 0) ? arr[n-nkpk-1] : 0) - ((n-nkpk-nb-1 >= 0) ? arr[n-nkpk-nb-1] : 0)) * y / 100)
            + ((((n-nkpk-nb-1 >= 0) ? arr[n-nkpk-nb-1] : 0) - ((n-nkpk-na-nb-1 >= 0) ? arr[n-nkpk-na-nb-1] : 0)) * x / 100);
            // printf("%llu %llu\n", sum1, sum2);
            if(sum1 < k && sum2 < k) continue;
            if(sum1 >= k || sum2 >= k) {
                bisa = true;
                break;
            }
        }
        printf("Kasus Uji #%d: %d\n", i, (bisa) ? j : -1);
    }
    return 0;
}