#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define pb push_back

struct DSU {
    int n;
    vector<int> f;
    DSU(int n) :n(n) {
        f = vector<int>(n + 1);
        iota(all(f), 0);
    }
    int Find(int x) {
        return f[x] == x ? x : Find(f[x]);
    }
    bool merge(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        if(fu == fv) return 0;
        f[fv] = fu;
        return 1;
    }
    bool connect(int u, int v) {
        int fu = Find(u);
        int fv = Find(v);
        return fu == fv;
    }
};

struct edge {
    int u, v, w, id;
    bool operator<(const edge& other) const {
        return w > other.w;
    }
};

int n, m, k;
vector<edge> e;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    vector<DSU> dsu;
    vector<int> ans(m + 1);
    for(int i = 1;i<=k;++i) dsu.pb(DSU(n));
    for(int i = 1;i<=m;++i) {
        edge cur;
        cin>>cur.u>>cur.v>>cur.w;
        cur.id = i;
        e.pb(cur);
    }
    sort(all(e));
    // enumerage edges from big to small
    for(edge i : e) {
        int& u = i.u;
        int& v = i.v;
        int& id = i.id;
        int l = 0, r = k - 1, res = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(dsu[mid].connect(u, v)) l = mid + 1;
            else {
                r = mid - 1;
                res = mid + 1;
            }
        }
        res == -1 ? ans[id] = 0 : dsu[res - 1].merge(u, v), ans[id] = res;
    }
    for(int i = 1;i<=m;++i) cout<<ans[i]<<'\n';
    return 0;
}
