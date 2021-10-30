#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

string a[N];

struct Trie {
    struct node {
        int e[26] = {0};
    } pos[N];
    int tot = 1, cnt[N];
    bool update(int rt, string& a, int cur) {
        if(cnt[rt]) return 1;
        if(cur == a.size()) {
            cnt[rt]++;
            return 0;
        } 
        if(!pos[rt].e[a[cur] - '0']) {
            pos[rt].e[a[cur] - '0'] = ++tot;
        }
        return update(pos[rt].e[a[cur] - '0'], a, cur + 1);
    }
} trie;

int main() {
#ifdef LOCAL 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1;i<=n;++i) {
        if(trie.update(1, a[i], 0)) {
            cout<<"YES"<<'\n';
            return 0;
        }
    }
    cout<<"NO"<<'\n';
    return 0;
}
