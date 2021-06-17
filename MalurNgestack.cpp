#include <bits/stdc++.h>
using namespace std;

int solpertamaku(vector<int> &arr, int n, int start, int xored, int tallest) {
    for(int i=start+1; i<n; i++) if(tallest <= arr[i]) xored ^= arr[i], tallest = arr[i];
    return xored;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, maxxored = 1;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n - 1; i++) maxxored = max(maxxored, solpertamaku(arr, n, i, arr[i], arr[i]));
    cout<<maxxored<<'\n';
}