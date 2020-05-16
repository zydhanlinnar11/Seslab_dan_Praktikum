#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void gots() {
    ll n, m, x, tmp, sum=0, amax = 0, bmax = 0;
    cin>>n>>m>>x;
    vector<ll> a, b;
    for(int i=0; i<n; i++) {
        cin>>tmp;
        a.push_back(tmp + ((i > 0) ? a[i - 1] : 0));
    }
    for(int i=0; i<m; i++) {
        cin>>tmp;
        b.push_back(tmp + ((i > 0) ? b[i - 1] : 0));
    }
    if(a[0] > x && b[0] > x) {
        cout<<"0\n";
        return;
    }
    if(a[0] > x) {
        for(int i=0; i<m; i++)
            if(b[i] > x) {
                cout<<i<<'\n';
                return;
            }
    }
    if(b[0] > x) {
        for(int i=0; i<n; i++)
            if(a[i] > x) {
                cout<<i<<'\n';
                return;
            }
    }
    amax = m;
    for(int i=0; i<m; i++)
        if(b[i] > x) {
            amax = i;
            break;
        }
    for(int i=0; i<n; i++) {
        if(a[i] > x)
            break;
        if(a[i] + b[0] > x) {
            amax = max(amax, (ll)i + 1);
            continue;
        }
        ll start = 0, end = m - 1;
        while(start <= end) {
            ll mid = start + ((end - start) / 2);
            if(start == end || mid == start) {
                if(((mid + 1) < m) && (a[i] + b[mid + 1] <= x)) {
                    start = mid + 1;
                    continue;
                }
                amax = max(amax, mid + i + 2);
                break;
            }
            if(a[i] + b[mid] > x)
                end = mid - 1;
            else {
                if(((mid + 1) < m) && a[i] + b[mid + 1] <= x)
                    start = mid + 1;
                else start = mid;
            }
        } 
    }
    cout<<amax<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int games;
    cin>>games;
    while(games--)
        gots();
    return 0;
}