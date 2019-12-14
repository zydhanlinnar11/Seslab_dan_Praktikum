#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define ull unsigned long long
#define mod 1000000007

bool prime[1001];

bool isPrime(int n) {
    int i;
    for(i=2; i*i<=n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void sieve() {
    memset(prime, true, sizeof(prime)); 
    prime[1] = false;
    int p;
    for (p=2; p*p<=1000; p++) {
        if (prime[p] == true) {
            int i;
            for (i=p*p; i<=1000; i += p) 
                prime[i] = false; 
        } 
    } 
} 


ull kalimod(ull a, ull b) {
    ull hasil = 0;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            hasil += a;
            hasil %= mod;
        }

        a *= 2;
        a %= mod;
        b /=2;
    }
    return hasil % mod;
}

int main() {
    sieve();
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++) {
        int m, h, j;
        scanf("%d %d", &m, &h);
        ull res=1;
        for(j=1; j<=h; j++) {
            //printf("%d %s\n", j, prime[j] ? "PRIMA" : "BUKAN PRIMA");
            if(j==1) res *= m;
            else if(!prime[j]) {
                res = kalimod(res, m-1);
            } else if (prime[j]) {
                //printf("Masuk %d\n", j);
                res = kalimod(res, m);
            }
        }
        printf("%llu\n", res);
    }
    return 0;
}