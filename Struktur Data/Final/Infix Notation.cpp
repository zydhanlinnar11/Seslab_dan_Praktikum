#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 3331
ll A = 10080, B = 1100, C = A + B, D = B + C;

int presedensi(char c) { 
    if(c == '*') 
        return 2; 
    else if(c == '+' || c == '-') 
        return 1; 
    else
        return -1; 
}

ll getVal(char c) {
    if(c == 'A')
        return A;
    if(c == 'B')
        return B;
    if(c == 'C')
        return C;
    return D;
}

queue<char> infixToPostfix(string s) { 
    stack<char> st;
    queue<char> out;
    int l = s.length();
    for(int i = 0; i < l; i++) {
        if(s[i] == ' ')
            continue;
        else if(s[i] >= 'A' && s[i] <= 'Z') 
            out.push(s[i]); 
        else if(s[i] == '(')
            st.push('(');
        else if(s[i] == ')') { 
            while(!st.empty() && st.top() != '(') { 
                char c = st.top(); 
                st.pop(); 
            out.push(c); 
            } 
            if(st.top() == '(') { 
                char c = st.top(); 
                st.pop(); 
            } 
        } else { 
            while(!st.empty() && presedensi(s[i]) <= presedensi(st.top())) { 
                char c = st.top(); 
                st.pop(); 
                out.push(c); 
            } 
            st.push(s[i]); 
        } 

    }
    while(!st.empty()) { 
        char c = st.top(); 
        st.pop(); 
        out.push(c); 
    }
    return out;
}

ll modex(ll a, ll b) {
    ll hasil=1;
    a %= mod;

    while(b > 0) {
        if(b % 2 == 1) {
            hasil = ((hasil % mod) * (a % mod)) % mod;
        }

        b /= 2;
        a = ((a % mod) * (a % mod)) % mod;
    }
    return hasil;
}

void in() {
    int n;
    cin>>n;
    getchar();
    string operation;
    getline(cin, operation);
    queue<char> postfix = infixToPostfix(operation);
    stack<ll> op;
    while(!postfix.empty()) {
        char c = postfix.front();
        postfix.pop();
        if(c >= 'A' && c <= 'D')
            op.push(getVal(c));
        else {
            ll a = op.top();
            op.pop();
            ll b = op.top();
            op.pop();
            if(c == '+')
                op.push(b + a);
            else if(c == '-')
                op.push(b - a);
            else if(c == '*')
                op.push(b * a);
        }
    }
    ll bilangan = op.top(), digit = log10(bilangan) + 1;
    ll res = 0;
    op.pop();
    for(int i=0; i<n; i++) {
        res = (res + modex(10, i * digit)) % mod;
    }
    cout<<((res * (bilangan % mod)) % mod)<<'\n';
}

int main() {
    int t;
    cin>>t;
    getchar();
    while(t--)
        in();
    return 0;
}