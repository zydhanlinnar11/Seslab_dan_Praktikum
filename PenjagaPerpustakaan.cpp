#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <time.h>
#include <deque>
using namespace __gnu_pbds;
using namespace std;
typedef unsigned long long ull;
typedef pair<string, string> pss;
typedef tree<pss, null_type, less<pss>, rb_tree_tag, tree_order_statistics_node_update> AVL;
#define MOD 1000000007
#define mp(x, y) make_pair(x, y)

void insertbuku(AVL &avl, map<string, string> &penulis) {
    while(true) {
        string book;
        getline(cin, book);
        if(book == "END") break;
        string title = book.substr(0, book.find(" by "));
        string writer = book.substr(title.length() + 4, book.length() - title.length() - 4);
        avl.insert(mp(writer, title));
        penulis[title] = writer;
    }
    // for(auto i: avl) cout<<i.first<<' '<<i.second<<'\n';
}

#define mp(x, y) make_pair(x, y)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    AVL avl;
    map<string, string> penulis;
    insertbuku(avl, penulis);
    set<pss> returned;
    while(true) {
        string cmd;
        getline(cin, cmd);
        if(cmd == "END") break;
        if(cmd.find("PINJAM ") != string::npos) {
            string title = cmd.substr(7, cmd.length() - 7);
            // cout<<title<<'\n';
            string writer = penulis[title];
            if(avl.find(mp(writer, title)) != avl.end())
                avl.erase(mp(writer, title));
            else {
                returned.erase(mp(writer, title)); 
            }
        } else if(cmd.find("KEMBALI ") != string::npos) {
            string title = cmd.substr(8, cmd.length() - 8);
            // cout<<title<<'\n';
            string writer = penulis[title];
            returned.insert(mp(writer, title));
        } else {
            for(auto i: returned) {
                string title = i.second;
                string writer = i.first;
                int pos = avl.order_of_key(mp(writer, title));
                avl.insert(mp(writer, title));
                if(pos == 0) {
                    cout<<"Put "<<title<<" first\n";
                } else {
                    cout<<"Put "<<title<<" after "<<avl.find_by_order(pos - 1)->second<<'\n';
                }
            }
            returned.clear();
            cout<<"END\n";
        }
    }
}