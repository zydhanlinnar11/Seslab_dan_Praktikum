#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &par, int x) {
    if(par[x] != x)
        return par[x] = find(par, par[x]);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<int> par(n, 0), _rank(n, 0);
    for(int i=0; i<n; i++)
        par[i] = i, _rank[i] = 1;
    for(int i=0; i<m; i++) {
        int k;
        cin>>k;
        int v = -1;
        for(int j=0; j<k; j++) {
            int u, paru, parv;
            cin>>u;
            if(j == 0) {
                v = u;
                continue;
            }
            paru = find(par, u), parv = find(par, v);
            if(paru == parv) continue;
            if(_rank[paru] > _rank[parv])
                _rank[paru] += _rank[parv], par[parv] = par[paru];
            else _rank[parv] += _rank[paru], par[paru] = par[parv];
        }
    }
    for(int i=0; i<n; i++) {
        cout<<_rank[find(par, i)]<<" \n"[i == n - 1];
    }
    return 0;
}