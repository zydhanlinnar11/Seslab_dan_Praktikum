#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
#define mp(x, y) make_pair(x, y)

void prog() {
    int n, m;
    cin>>n>>m;
    vector<int> arr[n];
    for(int i=0; i<n; i++) {
        arr[i] = vector<int>(m, 0);
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    pq.push(mp(arr[0][0], mp(0, 0)));
    vector<bool> visited[n];
    for(auto &i: visited) i = vector<bool>(m, false);
    pii steps[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while(!pq.empty()) {
        auto currNode = pq.top();
        pq.pop();
        if(currNode.second.first == n - 1 && currNode.second.second == m - 1) {
            cout<<currNode.first<<'\n';
            return;
        }
        for(pii step: steps) {
            pii dest = mp(currNode.second.first + step.first, currNode.second.second + step.second);
            if(dest.first < 0 || dest.first >= n || dest.second < 0 || dest.second >= m || visited[dest.first][dest.second]) continue;
            visited[dest.first][dest.second] = true;
            pq.push(mp(currNode.first + arr[dest.first][dest.second], dest));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) prog();
    return 0;
}