#include <bits/stdc++.h>
using namespace std;
using ull = unsigned __int128;
const int N = 2e5 + 10;
#define pb push_back

unordered_set<int> l;
map<ull, int> vis[N];
map<ull, vector<int> > pos;

string s;
int q, n, k[N];
ull pw[N], h[N], hsh[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>s;
    s = '@' + s;
    n = s.size() - 1;
    pw[0] = 1;
    for(int i = 1;i<=n;++i) {
        pw[i] = pw[i - 1] * 131;
        h[i] = h[i - 1] * 131 + s[i];
    }
    cin>>q;
    for(int i = 1;i<=q;++i) {
        string x;
        ull a = 0;
        cin>>x>>k[i];
        for(auto c : x) a = a * 131 + c;
        hsh[i] = a;
        vis[x.size()][a] = 1;
        l.insert(x.size());
    }
    for(auto len : l) {
        for(int i = len;i<=n;++i) {
            if(vis[len][h[i] - h[i - len] * pw[len]]) 
                pos[h[i] - h[i - len] * pw[len]].pb(i - len + 1);
        }
    }
    for(int i = 1;i<=q;++i) 
        cout<<(pos[hsh[i]].size() < k[i] ? -1 : pos[hsh[i]][k[i] - 1])<<'\n';
    return 0;
}