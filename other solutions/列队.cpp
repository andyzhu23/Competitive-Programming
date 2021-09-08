#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
using vi = vec<int>;
using ll = long long;
using vll = vec<ll>;
#define pb push_back

const int N = 3e5 + 1;

struct SPLAY {
    vll val = vll(1);
    vi lc = vi(1), rc = vi(1), fa = vi(1), size = vi(1), cnt = vi(1);
    int root = 0, tot = 0;
    queue<int> trash;
    inline bool chk(int x) {return rc[fa[x]] == x;}

    inline void update(int rt) {
        size[rt] = size[lc[rt]] + size[rc[rt]] + cnt[rt];
        fa[lc[rt]] = fa[rc[rt]] = rt;
    }

    int node;
    inline void new_node(int& rt, ll x, int c) {
        if(trash.empty()) {
            rt = ++tot;
            node = rt;
            fa.pb(0);
            val.pb(x);
            lc.pb(0);
            rc.pb(0);
            size.pb(c);
            cnt.pb(c);
        } else {
            rt = trash.front(); trash.pop();
            node = rt;
            fa[rt] = 0;
            val[rt] = x;
            lc[rt] = 0;
            rc[rt] = 0;
            size[rt] = c;
            cnt[rt] = c;
        }
    }
    inline void turn(int x) {
        int y = fa[x];
        int z = fa[y];
        int tmp;
        if(chk(x)) {
            // left turn
            tmp = lc[x];
            lc[x] = y;
            rc[y] = tmp;
        } else {
            // right turn
            tmp = rc[x];
            rc[x] = y;
            lc[y] = tmp;
        }
        fa[x] = z;
        fa[y] = x;
        fa[tmp] = y;
        lc[z] == y ? lc[z] = x : rc[z] = x;
        update(y);
        update(x);
    }

    inline void splay(int& rt) {
        while(fa[rt]) {
            if(fa[fa[rt]]) {
                if(chk(fa[rt]) == chk(rt)) turn(fa[rt]);
                else turn(rt);
            }
            turn(rt);
        }
        root = rt;
    }

    inline int insert(int& rt, ll x, int c) {
        int ans;
        if(rt == 0) {
            new_node(rt, x, c);
            rt = node;
            return rt;
        } else ans = insert(rc[rt], x, c);
        update(rt);
        return ans;
    }

    inline void insert(ll x, int c) {
        int rt = insert(root, x, c);
        splay(rt);
    }

    inline int id(int rt, int& x) {
        if(rt == 0) return -1;
        if(size[lc[rt]] >= x) return id(lc[rt], x);
        else if(size[lc[rt]] + cnt[rt] >= x) return rt;
        else return id(rc[rt], x -= size[lc[rt]] + cnt[rt]);
    }

    inline int max(int rt) {
        if(rc[rt]) return max(rc[rt]);
        return rt;
    }

    inline int join(int& x, int& y) {
        if(!(x * y)) return x + y;
        fa[x] = fa[y] = 0;
        x = max(x);
        splay(x);
        root = x;
        rc[x] = y;
        fa[y] = x;
        update(x);
        return x;
    }

    inline ll erase(int x) {
        int rt = id(root, x);
        if(cnt[rt] != 1) {
            int pos = 0, l = 0, r = 0;
            new_node(pos, val[rt] + x - size[lc[rt]] - 1, 1);
            pos = node;
            if(size[lc[rt]] + 1 != x) {
                new_node(l, val[rt], x - size[lc[rt]] - 1);
                l = node;
                lc[l] = lc[rt];
                fa[lc[rt]] = l;
                update(l);
            }
            if(size[lc[rt]] + cnt[rt] != x) {
                new_node(r, val[rt] + x - size[lc[rt]], size[lc[rt]] + cnt[rt] - x);
                r = node;
                rc[r] = rc[rt];
                fa[rc[rt]] = r;
                update(r);
            }
            if(l) {
                lc[pos] = l;
                fa[l] = pos;
            } else {
                lc[pos] = lc[rt];
                fa[lc[rt]] = pos;
            }

            if(r) {
                rc[pos] = r;
                fa[r] = pos;
            } else {
                rc[pos] = rc[rt];
                fa[rc[rt]] = pos;
            }
            fa[pos] = fa[rt];
            lc[fa[rt]] == rt ? lc[fa[rt]] = pos : rc[fa[rt]] = pos;
            if(rt == root) {
                fa[root] = 0;
                root = pos;
            }
            trash.push(rt);
            rt = pos;
            update(rt);
        }
        splay(rt);
        trash.push(rt);
        root = join(lc[rt], rc[rt]);
        fa[root] = 0;
        return val[rt];
    }


} last;

SPLAY sp[N];

int n, m, q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    for(ll i = 1, val = 1;i<=n;i++, val += m) {
        sp[i].insert(val, m - 1);
        last.insert(m * i, 1);
    }
    while(q--) {
        int x, y;
        cin>>x>>y;
        ll lef;
        if(y % m == 0) {
            lef = last.erase(x);
            cout<<lef<<'\n';
            last.insert(lef, 1);
            continue;
        }
        lef = sp[x].erase(y);
        cout<<lef<<'\n';
        int nxt = x;
        ll val = last.val[last.id(last.root, nxt)];
        sp[x].insert(val, 1);
        last.erase(x);
        last.insert(lef, 1);
    }
    return 0;
}