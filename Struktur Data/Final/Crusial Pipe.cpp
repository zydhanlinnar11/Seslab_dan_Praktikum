#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, *arr, sum = 0, computed = 0;
ll calculate() {
    vector<ll> a, b;
    ll suma = 0, sumb = 0;
    a.resize(n >> 1);
    b.resize(n >> 1);
    for(ll i=0; i < (n >> 1); i++)
        a[i] = arr[i], suma += arr[i];
    for(ll i=(n >> 1); i < n; i++)
        b[i - (n >> 1)] = arr[i], sumb += arr[i];
    for(ll i=0; i< (n >> 1); i++) {
        ll diff = abs(suma - sumb);
        for(ll j=0; j< (n >> 1); j++) {
            ll newa = suma - a[i] + b[j], newb = sumb - b[j] + a[i];
            ll newdiff = abs(newa - newb);
            if(newdiff < diff) {
                suma = newa;
                sumb = newb;
                ll tmp = a[i];
                a[i] = b[j];
                b[j] = tmp;
            }
        }
    }
    return abs(suma - sumb);
}

vector<ll> *adjList;
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
            if(!sudah[*i] && (curr != v || (*i) != u) && (curr != u || (*i) != v)) {
                sudah[*i] = true;
                node.push(*i);
            }
        }
    }
    return pool;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> crucialPipe;
    cin>>n;
    arr = new ll[n];
    adjList = new vector<ll>[n];
    for(ll i = 0; i<n; i++)
        cin>>arr[i], sum += arr[i];
    sort(arr, arr + n);
    ll m;
    cin>>m;
    vector<pair<ll, ll>> edgelist;
    edgelist.resize(m);
    for(ll i=0; i<m; i++) {
        ll u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        edgelist[i] = make_pair(u, v);
    }
    for(ll i=0; i<m; i++) {
        ll u = edgelist[i].first, v = edgelist[i].second;
        ll pool = bfs(edgelist[i]);
        if(pool != n) {
            crucialPipe.push(make_pair(min(u, v), max(u, v)));
        }
    }
    cout<<calculate()<<' '<<crucialPipe.size()<<'\n';
    for(int i=1; !crucialPipe.empty(); i++) {
        ll u = crucialPipe.top().first, v = crucialPipe.top().second;
        crucialPipe.pop();
        cout<<"Pipa #"<<i<<": "<<u<<' '<<v<<'\n';
    }
}