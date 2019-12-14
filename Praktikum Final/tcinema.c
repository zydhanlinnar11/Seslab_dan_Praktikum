#include <stdio.h>

int main() {
    unsigned i, t;
    scanf("%u", &t);
    for(i=1; i<=t; i++) {
        unsigned long long aa, n, k;
        scanf("%llu %llu", &k, &n);
        if(n==1) aa = 0;
        else if(n%3==2) {
            aa = n/3;
            aa = (aa*(aa+1))/2;
        }
        else if(n%3==1) {
            aa = n-2;
            aa /= 3;
            aa = (aa*(aa+1))/2;
        }
        else if(n%3 == 0) {
            aa = n-1;
            aa /= 3;
            aa = (aa*(aa+1))/2;
            aa++;
        }
        printf("Kasus #%u:\n", i);
        printf("%llu %s\n", aa, (aa >= k) ? "YA" : "TIDAK");
    }

    return 0;
}