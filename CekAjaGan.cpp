#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n;
    cin>>n;
    set<ull> st;
    for(ull i=0; i<n; i++) {
        ull tmp;
        cin>>tmp;
        if(st.find(tmp) != st.end()) {
            cout<<"G\n";
            return 0;
        }
        st.insert(tmp);
    }
    cout<<"Y\n";
}