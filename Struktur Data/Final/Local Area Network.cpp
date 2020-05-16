#include <bits/stdc++.h>
using namespace std;
#define si srvList[i]
#define sk srvList[k]

typedef struct srv {
    string id;
    int n_data, lantai;
    unordered_set<string> data;
} server;

int main() {
    int n, m, koneksi = 0;
    cin>>n;
    vector<server> srvList;
    srvList.resize(n);
    for(int i=0; i<n; i++) {
        cin>>si.id>>si.n_data>>si.lantai;
        for(int j=0; j<si.n_data; j++) {
            string data;
            cin>>data;
            si.data.insert(data);
        }
    }
    cin>>m;
    for(int i=1; i<=m; i++) {
        unordered_set<int> sambungan;
        set<pair<int, string>> pq;
        int n_data, lantai;
        cin>>n_data>>lantai;
        for(int j=0; j<n_data; j++) {
            string data;
            cin>>data;
            int srvindex = -1, selisih = INT_MAX;
            for(int k=0; k<n; k++) {
                if(sk.data.count(data) > 0 && abs(sk.lantai - lantai) < selisih)
                    srvindex = k, selisih = abs(sk.lantai - lantai);
                if(sk.data.count(data) > 0) sambungan.insert(k);
            }
            pq.insert(make_pair(selisih, data));
        }
        cout<<"Client "<<i<<":\n";
        for(auto j=pq.begin(); j != pq.end(); j++)
            cout<<(*j).second<<'\n';
        koneksi += sambungan.size();
    }
    cout<<"Total Koneksi: "<<koneksi<<'\n';
}