#include <bits/stdc++.h>
using namespace std;

typedef struct gbr {
    string commitList[1050];
    unordered_set<int> availableID;
    int lastID = 0, activecommit = 0;
} gitBranch;

pair<string, gitBranch> newBranch(string name) {
    gitBranch tmp;
    for(int i=0; i<1050; i++)
        tmp.commitList[i] = "";
    return make_pair(name, tmp);
}

int main() {
    string active = "master";
    unordered_map<string, gitBranch> branch;
    branch.insert(newBranch("master"));
    branch.insert(newBranch("feature"));
    while(1) {
        string cmd;
        cin>>cmd;
        if(cmd == "quit")
            return 0;
        else if(cmd == "commit") {
            string name;
            cin>>name;
            branch[active].availableID.insert(branch[active].lastID);
            branch[active].commitList[branch[active].lastID] = name;
            branch[active].activecommit = branch[active].lastID;
            branch[active].lastID++;
        } else if(cmd == "reset") {
            int id;
            cin>>id;
            branch[active].activecommit = id;
            for(int i=branch[active].lastID - 1; i > id; i--) {
                if(branch[active].availableID.count(i) > 0) {
                    branch[active].availableID.erase(i);
                }
            }
            cout<<"Anda berada di commit "<<branch[active].commitList[branch[active].activecommit]<<'\n';
        } else if(cmd == "log") {
            if(branch[active].availableID.empty())
                cout<<'\n';
            else
                for(auto i=branch[active].lastID - 1; i >= 0; i--) {
                    if(branch[active].availableID.count(i) > 0)
                        cout<<i<<'\n'<<branch[active].commitList[i]<<'\n';
                }
        } else if(cmd == "checkout") {
            int id;
            cin>>id;
            if(branch[active].availableID.count(id) > 0) {
                cout<<"Anda berada di commit "<<branch[active].commitList[id]<<'\n';
                branch[active].activecommit = id;
            } else cout<<"ID tidak ditemukan\n";
        } else if(cmd == "status") {
            cout<<"Anda berada di commit "<<branch[active].commitList[branch[active].activecommit]<<'\n';
        } else if(cmd == "branch") {
            string tmpbr;
            cin>>tmpbr;
            active = tmpbr;
        } else if(cmd == "sync") {
            queue<pair<int, string>> q1, q2;
            for(int i=0; i<branch["master"].lastID; i++) {
                if(branch["master"].availableID.count(i) > 0)
                    q1.push(make_pair(i, branch["master"].commitList[i]));
            }
            for(int i=0; i<branch["feature"].lastID; i++) {
                if(branch["feature"].availableID.count(i) > 0)
                    q2.push(make_pair(i, branch["feature"].commitList[i]));
            }
            while(!q1.empty() && !q2.empty()) {
                if(q1.front().second == q2.front().second) {
                    q1.pop();
                    q2.pop();
                } else break;
            }
            if(active == "master") {
                while(!q2.empty()) {
                    branch["feature"].availableID.erase(q2.front().first);
                    q2.pop();
                }
            } else if(active == "feature") {
                while(!q1.empty()) {
                    branch["master"].availableID.erase(q1.front().first);
                    q1.pop();
                }
            }
        }
    }
    return 0;
}