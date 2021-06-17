#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, pii> pdii;
#define mp(x, y) make_pair(x, y)

int find(vector<int> &par, int x) {
    if(par[x] != x)
        return par[x] = find(par, par[x]);
    return x;
}

void prog(int tt) {
    int n, connected = 0;
    cin>>n;
    double sum = 0.0;
    vector<pdd> arr(n, {0.0, 0.0});
    vector<pdii> edgeList;
    for(int i=0; i<n; i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            edgeList.push_back(mp(sqrt(pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2)), mp(i, j)));
        }
    }
    vector<int> par(n, 0);
    for(int i=0; i<n; i++) par[i] = i;
    sort(edgeList.begin(), edgeList.end());
    for(pdii i: edgeList) {
        if(connected == n - 1) break;
        int parX = find(par, i.second.first), parY = find(par, i.second.second);
        if(parX == parY) continue;
        par[parX] = par[parY];
        sum += i.first;
        connected++;
    }
    cout<<setprecision(2)<<fixed<<sum<<(tt ? "\n\n" : "\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) prog(t);
}