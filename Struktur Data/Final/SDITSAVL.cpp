#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> AVL;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, tmp, cmd;
    AVL sd; unordered_set<ll> tampung;
    cin>>n;
    while(n--) {
        cin>>cmd;
        if(cmd == 1) {
            cin>>tmp;
            sd.insert(tmp);
            tampung.insert(tmp);
        } else {
            cin>>tmp;
            if(tampung.count(tmp) > 0)
                cout<<sd.order_of_key(tmp) + 1<<'\n';
            else cout<<"Data tidak ada\n";
        }
    }
}