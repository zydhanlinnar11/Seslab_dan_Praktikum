#include <bits/stdc++.h> 
using namespace std; 
const int N = 100000;
typedef long long ll;
typedef pair<ll, int> pli;
int n;
vector<pli> *graph; 
set<int> *cycles; 

void dfs_cycle(int u, int p, int color[], int mark[], int par[], int& cyclenumber) { 
	if (color[u] == 2) { 
		return; 
	} 

	if (color[u] == 1) {
		cyclenumber++; 
		int cur = p; 
		mark[cur] = cyclenumber; 

		while (cur != u) { 
			cur = par[cur]; 
			mark[cur] = cyclenumber; 
		} 
		return; 
	} 
	par[u] = p; 
	color[u] = 1; 

	for (pli v : graph[u]) { 
		if (v.second == par[u]) { 
			continue; 
		} 
		dfs_cycle(v.second, u, color, mark, par, cyclenumber); 
	} 
	color[u] = 2; 
} 

void addEdge(int u, int v, ll w) { 
	graph[u].push_back(make_pair(w, v)); 
	graph[v].push_back(make_pair(w, u)); 
}
bool **sudah, **jawab;
bool seprov(int a, int b, int cyclenum) {
    if(sudah[a][b])
        return jawab[a][b];
    for(int i=1; i<=cyclenum; i++) {
        if((cycles[i].find(a) != cycles[i].end() ) && (cycles[i].find(b) != cycles[i].end())) {
            sudah[a][b] = true;
            jawab[a][b] = true;
            return true;
        }
    }
    sudah[a][b] = true;
    jawab[a][b] = false;
    return false;
}
ll **dist;

void dijkstra(int s, int n, int cyclenum) {
    priority_queue <pli, vector <pli>, greater <pli>> pq;
    set<int> seen;
    memset(dist[s], -1, sizeof(ll) * (n + 1));
    dist[s][s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        pli now = pq.top();
        pq.pop();
        if(seen.find(now.second) != seen.end()) continue;
        seen.insert(now.second);
        for(int i = 0; i < graph[now.second].size(); i++) {
            int next = graph[now.second][i].second;
            int cost = graph[now.second][i].first;
            if(seprov(now.second, next, cyclenum))
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
	int edges;
    cin>>n>>edges;
    sudah = new bool*[n + 1];
    jawab = new bool*[n + 1];
    dist = new ll*[n + 1];
    for(int i=0; i<=n; i++) {
        sudah[i] = new bool[n + 1], jawab[i] = new bool[n + 1];
        dist[i] = new ll[n + 1];
        memset(sudah[i], 0, (n + 1) * sizeof(bool));
    }
    graph = new vector<pli>[N + 1];
    cycles = new set<int>[N + 1];
    for(int i=0; i<edges; i++){
        int u, v;
        ll w;
        cin>>u>>v>>w;
        addEdge(u, v, w);
    }
	int color[N + 1]; 
	int par[N + 1]; 
	int mark[N + 1]; 
	int cyclenumber = 0; 
	dfs_cycle(1, 0, color, mark, par, cyclenumber); 
	for (int i = 1; i <= edges; i++) { 
		if (mark[i] != 0) 
			cycles[mark[i]].insert(i); 
	} 
    for(int i=1; i<=n; i++) {
        dijkstra(i, n, cyclenumber);
    }
    int q;
    cin>>q;
    while(q--) {
        int x, y;
        cin>>x>>y;
        cout<<dist[x][y]<<'\n';
    }
} 
