#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

int main() {
    int n, x, ditanya;
    while(cin>>n>>x) {
        if(n == 0 && x == 0)
            break;
        bool dp[MAX];
        fill(dp, dp + MAX, false);
        for(int i=0; i<n; i++) {
            int depan, belakang;
            scanf("%d.%d", &depan, &belakang);
            depan = depan * 100 + belakang;
            if(i == x - 1) {
                ditanya = depan;
                continue;
            }
            for(int i=MAX - 1; i>=0; i--)
                if(dp[i])
                    dp[i + depan] = true;
            dp[depan - 1] = true;
        }
        if(ditanya > MAX / 2)
            cout<<"100.00\n";
        for(int i=MAX / 2 - ditanya; i < MAX && ditanya <= MAX / 2; i++)
            if(dp[i]) {
                printf("%.2lf\n", (ditanya) * 100.0 / (ditanya + i + 1));
                break;
            }
    }
    return 0;
}