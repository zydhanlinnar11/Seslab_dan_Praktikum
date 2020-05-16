#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, tmp;
    cin>>n;
    unordered_set<int> arr;
    bool sama = false;
    for(int i=0; i<n; i++) {
        cin>>tmp;
        if(arr.count(tmp) > 0)
            sama = true;
        else
            arr.insert(tmp);
    }
    if(!sama)
        cout<<"NAH GITU DONG, NGEGAS!\n";
    else cout<<"SUSAH BANGED WOI!\n";
    return 0;
}