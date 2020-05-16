#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> AVL;
using namespace std;
#define maxcons 100005
#define mod 1000000007

int main() {
    ll fact[maxcons], power[32];
    fact[0] = 1;
    power[0] = 1;
    for(ll i=1; i<maxcons; i++)
        fact[i] = (((fact[i - 1] % mod) * (i % mod)) % mod);
    for(ll i=1; i<32; i++)
        power[i] = (power[i - 1] * 2);
    ll n, sum = 1;
    cin>>n;
    ll p[n];
    AVL sorted, davl;
    for(ll i=0; i<n; i++) {
        cin>>p[i];
        sorted.insert(p[i]);
        davl.insert(i);
    }
    ll tmp = n - 1;
    for(ll i = 0; i < n; i++) {
        ll pi = sorted.order_of_key(p[i]);
        ll d = davl.order_of_key(pi);
        // cout<<d<<' ';
        davl.erase(pi);
        sum = ((sum % mod) + ((d % mod) * (fact[tmp--] % mod) % mod) % mod);
    }
    cout<<sum<<'\n';
}