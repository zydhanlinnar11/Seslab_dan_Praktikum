#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void parkir(int n, int k) {
    stack<pii> parkiran;
    priority_queue<pii, vector<pii>, greater<pii>> antrian;
    bool keluar[1000] = {0}, masuk[1000] = {0}, gbs = false;
    for(int i=0; i<n; i++) {
        int a, e;
        cin>>a>>e;
        antrian.push(make_pair(a, e));
        if(keluar[e] || masuk[a] || (a == e)) {
            gbs = true;
        } else if(!keluar[e])
            keluar[e] = true;
        else masuk[a] = true; 
    }
    if(gbs) {
        cout<<"Gak Bisa Woi\n";
        return;
    }
    for(int i=1; !antrian.empty() || !parkiran.empty(); i++) {
        if(!parkiran.empty() && parkiran.top().second == i) {
            parkiran.pop();
        }
        if(!parkiran.empty() && parkiran.top().second <= i) {
            cout<<"Gak Bisa Woi\n";
            return;
        }
        if(!antrian.empty() && antrian.top().first == i) {
            if(parkiran.size() == k || (!parkiran.empty() && antrian.top().second >= parkiran.top().second)) {
                cout<<"Gak Bisa Woi\n";
                return;
            } else {
                parkiran.push(antrian.top());
                if(antrian.top().second == antrian.top().first)
                    parkiran.pop();
                antrian.pop();
            }
        }
        if(!antrian.empty() && antrian.top().first <= i) {
            cout<<"Gak Bisa Woi\n";
            return;
        }
    }
    cout<<"Lancar Jaya\n";
}

int main() {
    while(1) {
        int n, k;
        cin>>n>>k;
        if((n == k) && (k == 0))
            return 0;
        parkir(n, k);
    }
    return 0;
}