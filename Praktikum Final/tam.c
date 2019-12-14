#include <stdio.h>
#include <math.h>
#define ll long long

int main() {
    int i, t;
    scanf("%d", &t);
    for(i=0; i<t; i++) {
        ll x1, y1, x2, y2, x3, y3;
        scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3);
        ll Ltemp = ((x2 - x1)*(y3 - y1)-(x3-x1)*(y2-y1));
        double L = ((double)Ltemp) / 2;
        printf("%.2lf\n", fabs(L));
    }
    return 0;
}