#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    int n = 1000000;
    assert(q >= 1 && q <= n);
    vector<int> arr(n, 0);
    arr[0] = 11;
    arr[1] = 15;
    for(int i=2; i<n; i++) {
        if(i < 11) arr[i] = arr[i - 1] + arr[i - 2];
        else if(i < 15) arr[i] = arr[i - 11] + arr[i - 2];
        else arr[i] = ((arr[i - 11] % MOD) + (arr[i - 15] % MOD)) % MOD;
    }
    while(q--) {
        int asked;
        cin>>asked;
        assert(asked >= 0 && asked < n);
        cout<<arr[asked]<<'\n';
    }
    return 0;
}