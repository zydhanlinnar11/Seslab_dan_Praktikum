#include <bits/stdc++.h>
using namespace std;

void kf() {
    string s;
    set<string> ss;
    char c;
    while(c = getchar()) {
        if(c == '\n' || c == EOF) {
            if(s != "") ss.insert(s);
            s = "";
            break;
        } else if(c == ' ') {
            if(s != "") ss.insert(s);
            s = "";
        } else s += c;
    }
    auto i = ss.begin();
    cout<<(*i);
    i++;
    for(; i != ss.end(); i++)
        cout<<' '<<(*i);
    cout<<'\n';
}

int main() {
    int n;
    cin>>n;
    getchar();
    while(n--)
        kf();
    return 0;
}