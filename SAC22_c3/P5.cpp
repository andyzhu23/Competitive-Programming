#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull h = 131;
const int N = 5e4 + 5;
unordered_set<ull> key, vis;
int n, m;
ull hsh[N], p[N];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>m;
    for(int i = 1;i<=n;++i) {
        string s; cin>>s;
        ull a = 0;
        for(char c : s) {
            if(c < 'a') c = c - 'A' + 'a';
            a = a * h + c;
        }
        key.insert(a);
    }
    while(m--) {
        string s; cin>>s;
        int n = s.size();
        p[0] = 1;
        int ans = 0;
        vis.clear();
        for(int i = 1;i<=n;++i) {
            if(s[i - 1] < 'a') s[i - 1] = s[i - 1] - 'A' + 'a';
            hsh[i] = hsh[i - 1] * h + s[i - 1];
            p[i] = p[i - 1] * h;
        }
        for(int l = 1;l<=25;++l) {
            for(int i = l;i<=n;++i) {
                ull a = hsh[i] - hsh[i - l] * p[l];
                if(key.count(a) && !vis.count(a)) {
                    vis.insert(a);
                    ++ans;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
