#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> *adjList;
ll *jarak;
bool *visited;
void dfs(ll dest, ll depth, ll l, ll weight) {
    if(depth > l)
        return;
    if(visited[dest] && weight >= jarak[dest])
        return;
    visited[dest] = true;
    jarak[dest] = weight;
    for(ll i=0; i<adjList[dest].size(); i++) {
        dfs(adjList[dest][i].first, depth + 1, l, adjList[dest][i].second + weight);
    }
}

int main() {
    ll v, e, vi, vj, w, x, l;
    cin>>v;
    cin>>e;
    adjList = new vector<pll>[v];
    for(ll i=0; i<e; i++) {
        cin>>vi>>vj>>w;
        adjList[vi].push_back(make_pair(vj, w));
    }
    cin>>x>>l;
    jarak = new ll[v], visited = new bool[v];
    for(ll i=0; i<v; i++)
        jarak[i] = INT64_MAX, visited[i] = false;
    dfs(x, 0, l, 0);
    for(ll i=0; i<v; i++) {
        if(jarak[i] == INT64_MAX)
            cout<<i<<" INFINITY\n";
        else cout<<i<<' '<<jarak[i]<<'\n';
    }
    return 0;
}