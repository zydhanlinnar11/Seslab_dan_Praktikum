#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<pair<int,pii>> edgeList;
int adjMat[150][150],p[150], n, m;
#define mod 31011
 
int find(int x) {
  if(p[x] < 0)
    return x;
  return p[x] = find(p[x]);
}
 
ll det(vector<pii> *edgeSelect) {
  vector<int> hmap;
  for(int i = 0; i < (*edgeSelect).size(); i++) {
      hmap.push_back((*edgeSelect)[i].first);
      hmap.push_back((*edgeSelect)[i].second);
  }
  sort(hmap.begin(), hmap.end());
  hmap.erase(unique(hmap.begin(), hmap.end()), hmap.end());
  int n = hmap.size() - 1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      adjMat[i][j] = 0;
  for(int i = 0; i < (*edgeSelect).size(); i++) {
    int u = lower_bound(hmap.begin(), hmap.end(), (*edgeSelect)[i].first) - hmap.begin();
    int v = lower_bound(hmap.begin(), hmap.end(), (*edgeSelect)[i].second) - hmap.begin();
    adjMat[u][u]++, adjMat[v][v]++, adjMat[u][v]--, adjMat[v][u]--;
  }
  ll res = 1;
  for(int i = 0; i < n; i++) {
    for(int j = (i + 1); j < n; j++) {
      while(adjMat[j][i]) {
        res *= -1;
        ll t = (adjMat[i][i] / adjMat[j][i]);
        for(int k = i; k < n; k++) {
          adjMat[i][k] = (adjMat[i][k] - adjMat[j][k] * t) % mod, adjMat[i][k] ^= adjMat[j][k];
          adjMat[j][k] ^= adjMat[i][k], adjMat[i][k] ^= adjMat[j][k];
        }
      }
    }
    if(adjMat[i][i] == 0) {
      return 0;
    } else res=(res * adjMat[i][i]) % mod;
  }
  return (res % mod + mod) % mod;
}
 
int main() {
  cin>>n>>m;
  for(int i = 0; i < 150; i++)
    p[i] = INT_MIN;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin>>a>>b>>c;
    edgeList.push_back(make_pair(c, make_pair(--a, --b)));
  }
  ll res=1;
  sort(edgeList.begin(), edgeList.end());
  int l, r = 0;
  while(r < edgeList.size()) {
    l = r++;
    while(r < edgeList.size() && edgeList[r].first == edgeList[l].first)
      r++;
    for(int i = l; i < r; i++) {
      int &u=edgeList[i].second.first, &v=edgeList[i].second.second;
      u=find(u);
      v=find(v);
    }
    for(int i = l; i < r; i++) {
      int u = edgeList[i].second.first;
      int v = edgeList[i].second.second;
      u = find(u);
      v = find(v);
      if(u != v)
        p[u] = v;
    }
    for(int i = 0; i < n; i++)
      if(p[i] < 0) {
        vector<pii> edgeSelect;
        for(int j = l; j < r; j++) {
          int u = edgeList[j].second.first;
          int v = edgeList[j].second.second;
          if(find(u) == i && find(v) == i)
            edgeSelect.push_back(make_pair(u, v));
        }
        res=(res * det(&edgeSelect)) % mod;
      }
    }
    int count = 0;
    for(int i = 0; i < n; i++)
      if(p[i] < 0)
        count++;
    if(count > 1) {
      cout<<"0\n";
      return 0;
    }
  cout<<(((res % mod) + mod) % mod)<<'\n';
}