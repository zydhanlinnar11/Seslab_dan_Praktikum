#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;
typedef pair<int, pis> piis;
typedef pair<int, piis> piiis;
#define mp(x, y) make_pair(x, y)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, m, n;
    cin>>t>>m>>n;
    vector<piiis> arr(t, mp(0, mp(0, mp(0, ""))));
    for(int i=0; i<t; i++) {
        cin>>arr[i].second.second.second>>arr[i].second.second.first>>arr[i].second.first;
        arr[i].first = arr[i].second.first - arr[i].second.second.first;
    }
    if(t < m + n) {
        cout<<"-1\n";
        return 0;
    }
    vector<string> singer(n, ""), dancer(m, "");
    sort(arr.rbegin(), arr.rend());
    int sum = 0;
    for(int i=0; i<n; i++) singer[i] = arr[i].second.second.second, sum += arr[i].second.first;
    for(int i=t - 1; i>=t - m; i--) dancer[t - i - 1] = arr[i].second.second.second, sum += arr[i].second.second.first;
    for(int i=n; i<t - m; i++)
        if(arr[i].first >= 0) singer.push_back(arr[i].second.second.second), sum += arr[i].second.first;
        else dancer.push_back(arr[i].second.second.second), sum += arr[i].second.second.first;
    sort(singer.begin(), singer.end());
    sort(dancer.begin(), dancer.end());
    cout<<sum<<"\n";
    for(int i=0; i<t; i++) {
        string nama = (i < singer.size() ? singer[i] : dancer[i - singer.size()]);
        cout<<nama<<" \n"[i == t - 1];
    }
}