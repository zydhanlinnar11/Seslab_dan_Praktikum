#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin>>n;
    if(n & 1) {
        ll k = (n - 1)/2, res = 1 + (2*k * (k + 1));
        ll tmp = res / 10, res2 = tmp + res;
        while(res != res2) {
            ll temp = (res2/10 - res/10);
            res = res2;
            res2 += temp;
        }
        cout<<res2<<'\n';
    } else {
        ll k = (n - 2)/2, res = 2 + (2*k * (k + 2));
        ll tmp = res / 10, res2 = tmp + res;
        while(res != res2) {
            ll temp = (res2/10 - res/10);
            res = res2;
            res2 += temp;
        }
        cout<<res2<<'\n';
    }
}