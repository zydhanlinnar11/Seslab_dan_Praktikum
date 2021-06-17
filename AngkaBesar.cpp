#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <time.h>
using namespace __gnu_pbds;
using namespace std;
typedef unsigned long long ull;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> AVL;
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    AVL avl;
    int t, n;
    cin>>t>>n;
    for(int i=0; i<t; i++) {
        int tmp;
        cin>>tmp;
        avl.insert(tmp);
    }
    cout<<*(avl.find_by_order(n - 1))<<'\n';
}