#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 105;
string s[N];
int a[N];

void solve() {
    int n, m;
    cin>>n>>m;
    swap(n, m);
    for(int i = 1;i<=n;++i) {
        cin>>s[i]>>a[i];
    }
    set<int> pos, test;
    for(int i = 0;i<m;++i) pos.insert(i);
    for(int i = 1;i<=n;++i) test.insert(i);
    while(!pos.empty() && !test.empty()) {
        bool flag = 0;
        for(auto x : pos) {
            set<int> b, c;
            vector<int> d, e;
            for(auto y : test) {
                if(s[y][x] == '0') b.insert(a[y]), d.pb(y); 
                else c.insert(a[y]), e.pb(y);
            }
            if(b.size() == 1) {
                for(auto f : d) test.erase(f);
                flag |= 1;
                break;
            }
            if(c.size() == 1) {
                for(auto f : e) test.erase(f);
                flag |= 1;
                break;
            }
        }
        if(!flag) {
            cout<<"LIE\n";
            return;
        }
    }
    cout<<"OK\n";
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}