#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin>>n;
    ll k = (n - 1)/2, fak = ((n & 1) ? 1 : 2), res = fak + (2*k * (k + fak));
    ll tmp = res / 10, res2 = tmp + res;
    while(res != res2) {
        ll temp = (res2/10 - res/10);
        res = res2;
        res2 += temp;
    }
    cout<<res2<<'\n';
}