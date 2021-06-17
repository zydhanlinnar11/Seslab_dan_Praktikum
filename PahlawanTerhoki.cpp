#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin>>n>>q;
    vector<int> pwr(n, 0);
    vector<int> currteam(n, 0);
    map<int, multiset<int>> teams;
    multiset<int> hoki;
    for(int i=0; i<n; i++) {
        int team;
        cin>>pwr[i]>>team;
        teams[team].insert(pwr[i]);
        currteam[i] = team;
    }
    for(auto i: teams)
        hoki.insert(*i.second.rbegin());
    for(int i=1; i<=q; i++) {
        int hero, team;
        cin>>hero>>team;
        hero--;
        hoki.erase(hoki.find(*teams[currteam[hero]].rbegin()));
        teams[currteam[hero]].erase(teams[currteam[hero]].find(pwr[hero]));
        if(!teams[currteam[hero]].empty())
            hoki.insert(*teams[currteam[hero]].rbegin());
        currteam[hero] = team;
        if(!teams[currteam[hero]].empty())
            hoki.erase(hoki.find(*teams[currteam[hero]].rbegin()));
        teams[currteam[hero]].insert(pwr[hero]);
        hoki.insert(*teams[currteam[hero]].rbegin());
        cout<<"Query "<<i<<": "<<*hoki.begin()<<'\n';
    }
}