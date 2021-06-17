#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define mpair make_pair
vector<pll> *adjList;
set<pll> crucialPipe;
ll n, m;
bool isCrucialPipe(ll a, ll b) {
    return ((crucialPipe.find(mpair(a, b)) != crucialPipe.end())
    || (crucialPipe.find(mpair(b, a)) != crucialPipe.end()));
}

ll bfs(pair<ll, ll> removed) {
    ll u = removed.first, v = removed.second, pool = 0;
    vector<bool> sudah(n, false);
    queue<ll> node;
    node.push(v);
    sudah[v] = true;
    while(!node.empty()) {
        ll curr = node.front();
        node.pop();
        pool++;
        for(auto i=adjList[curr].begin(); i != adjList[curr].end(); i++) {
            if(!sudah[(*i).second] && (curr != v || (*i).second != u) && (curr != u || (*i).second != v)) {
                sudah[(*i).second] = true;
                node.push((*i).second);
            }
        }
    }
    return pool;
}

ll **dist;
void dijkstra(ll s) {
    priority_queue <pll, vector <pll>, greater <pll>> pq;
    set<ll> seen;
    memset(dist[s], -1, sizeof(ll) * n);
    dist[s][s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        pll now = pq.top();
        pq.pop();
        if(seen.find(now.second) != seen.end()) continue;
        seen.insert(now.second);
        for(ll i = 0; i < adjList[now.second].size(); i++) {
            ll next = adjList[now.second][i].second;
            ll cost = adjList[now.second][i].first;
            if(!isCrucialPipe(now.second, next))
                cost = 0;
            if(now.first + cost < dist[s][next] || dist[s][next] == -1) {
                dist[s][next] = now.first + cost;
                pq.push({dist[s][next], next});
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<pll> edgeList;
    adjList = new vector<pll>[n];
    edgeList.resize(m);
    for(ll i=0; i<m; i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        adjList[u].push_back(mpair(w, v));
        adjList[v].push_back(mpair(w, u));
        edgeList[i] = mpair(u, v);
    }
    for(ll i=0; i<m; i++) {
        ll u = edgeList[i].first, v = edgeList[i].second;
        ll pool = bfs(edgeList[i]);
        if(pool != n) {
            crucialPipe.insert(mpair(min(u, v), max(u, v)));
        }
    }
    dist = new ll*[n];
    for(ll i=0; i<n; i++)
        dist[i] = new ll[n];
    for(ll i=0; i<n; i++)
        dijkstra(i);
    ll q;
    cin>>q;
    while(q--) {
        ll x, y;
        cin>>x>>y;
        cout<<dist[--x][--y]<<'\n';
    }
}