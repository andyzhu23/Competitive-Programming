#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 1e6 + 10;
string a, b;
unordered_map<int, int> nxt;
vector<int> lst;
ull h[N], key, base = 131, p[N];
deque<char> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifndef LOCAL
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
#endif
    cin>>a>>b;
    for(char c : b) key = key * base + c;
    p[0] = 1;
    for(int i = 1;i<=1e6 + 1;++i) p[i] = p[i - 1] * base;
    for(int i = 1;i<=a.size();++i) h[i] = h[i - 1] * base + a[i - 1];
    int last = 0;
    for(int i = 0;i<b.size() - 1;++i) {
        dq.push_back(a[i]);
        nxt[i] = i + 1;
    }
    last = b.size() - 1;
    int out = 0;
    for(int i = -b.size(); i<0;++i) {
        nxt[i] = i + 1;
        lst.push_back(i);
    }
    for(int i = b.size();i<=a.size();++i) {
        h[i] = h[last] * base + a[i - 1];
        dq.push_back(a[i - 1]);
        nxt[last] = i;
        last = i;
        if(out >= 0 && h[i] - h[out] * p[b.size()] == key) {
            last = out;
            for(int i = 1;i<=b.size();++i) {
                if(i > 1) {
                    lst.pop_back();
                }
                dq.pop_back();
            }
            out = lst.back();
            out = nxt[out];
            continue;
        }
        lst.push_back(out);
        out = nxt[out];
    }
    while(!dq.empty()) {
        cout<<dq.front();
        dq.pop_front();
    }
    cout<<'\n';
    return 0;
}
