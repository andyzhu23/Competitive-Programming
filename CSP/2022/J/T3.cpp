#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;
vector<char> stk;

struct node {
    int x, u, v;
};
vector<node> sk;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>s;
    for(auto c : s) {
        if(c == '0' || c == '1') {
            t += c;
            if(!stk.empty() && stk.back() == '&') t += stk.back(), stk.pop_back();
        } else if(c == ')') {
            while(stk.back() != '(') t += stk.back(), stk.pop_back();
            stk.pop_back();
            if(!stk.empty() && stk.back() == '&') t += stk.back(), stk.pop_back();
        } else if(c == '|') {
            while(!stk.empty() && stk.back() != '(') t += stk.back(), stk.pop_back();
            stk.push_back(c);
        } else stk.push_back(c);
    }
    while(!stk.empty()) t += stk.back(), stk.pop_back();
    for(auto c : t) {
        if(c == '0' || c == '1') sk.push_back({c - '0', 0, 0});
        else if(c == '&') {
            auto[v, a, b] = sk.back();
            sk.pop_back();
            auto[u, x, y] = sk.back();
            sk.pop_back();
            if(u == 0) sk.push_back({u & v, x + 1, y});
            else sk.push_back({u & v, x + a, y + b});
        } else {
            auto[v, a, b] = sk.back();
            sk.pop_back();
            auto[u, x, y] = sk.back();
            sk.pop_back();
            if(u == 1) sk.push_back({u | v, x, y + 1});
            else sk.push_back({u | v, x + a, y + b});
        }
    }
    cout<<sk.back().x<<'\n'<<sk.back().u<<' '<<sk.back().v<<'\n';
    return 0;
}
