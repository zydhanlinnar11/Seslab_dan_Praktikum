#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

string prog() {
    ll n;
    cin>>n;
    assert(n >= 1 && n <= 1000000000000000000);
    if(n > 139 || n % 11 == 0 || n % 15 == 0) return "YES\n";
    for(int i=0; i*15 <= n; i++)
        if((n - i * 15) % 11 == 0) return "YES\n";
    return "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    assert(t >= 1 && t <= 1000000);
    while(t--) cout<<prog();
}