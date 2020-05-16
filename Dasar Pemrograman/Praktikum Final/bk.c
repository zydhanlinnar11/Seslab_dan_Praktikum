#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int gcdku(int a, int b) {
    if(a % b == 0) return b;
    else return gcdku(b, a%b);
}

int main() {
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++) {
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        int gcdd;
        if (b>a) {
            gcdd = gcdku(b, a);
        } else gcdd = gcdku(a,b);
        if(x % gcdd != 0) printf("0\n");
        else {
            int kali = 0;
            int sa=0;
            while(sa*a<=x) {
                if((x-(sa*a)) % b == 0) kali++;
                sa++;
            }
            printf("%d\n", kali);
        }
    }
    return 0;
}