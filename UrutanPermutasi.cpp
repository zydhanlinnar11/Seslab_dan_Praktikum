#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef unsigned long long ull;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> AVL;
#define MOD 1000000007

// Spoiler : aslinya testcasenya ada yg salah, yang ac malah solusiku yang ga optimal.

void perm() {
    int n;
    cin>>n;
    ull index = 0;
    vector<unsigned> arr(n, 0U); 
    AVL avl;
    ull factorial[100001];
    factorial[0] = 1;
    for(int i=1; i<=100000; i++) factorial[i] = (factorial[i - 1] * i) % MOD;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        avl.insert(arr[i]);
    }
    for(int i=0; i<n; i++) {
        int curr_index = avl.order_of_key(arr[i]);
        int curr_perm = n - i - 1;
        avl.erase(arr[i]);
        index += (factorial[curr_perm] * curr_index) % MOD;
        index %= MOD;
    }
    cout<<index + 1<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    perm();
}
