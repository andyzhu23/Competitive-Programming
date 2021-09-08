#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct Splay {
    int lc[N], rc[N], size[N], cnt[N], val[N], fa[N], root, tot;
    bool lazy[N];
    bool chk(int rt) {return rc[fa[rt]] == rt;}
    void update(int rt) {
        size[rt] = size[lc[rt]] + size[rc[rt]] + cnt[rt];
        fa[lc[rt]] = fa[rc[rt]] = rt;
    }
    void push_down(int rt) {
        if(lazy[rt]) {
            swap(lc[rt], rc[rt]);
            lazy[lc[rt]] = !lazy[lc[rt]];
            lazy[rc[rt]] = !lazy[rc[rt]];
            lazy[rt] = 0;
        }
    }
    void turn(int x) {
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

    void splay(int rt, int goal) {
        while(fa[rt] != goal) {
            if(fa[fa[rt]] != goal) {
                if(chk(rt) == chk(fa[rt])) turn(fa[rt]);
                else turn(rt);
            }
            turn(rt);
        }
        if(goal == 0) {
            root = rt;
            fa[root] = 0;
        }
    }

    void splay(int rt) {
        splay(rt, 0);
    }

    int insert(int& rt, int x) {
        int ans;
        if(rt == 0) {
            rt = ++tot;
            lc[rt] = rc[rt] = 0;
            size[rt] = 1;
            cnt[rt] = 1;
            val[rt] = x;
            ans = rt;
        } else if(val[rt] == x) {
            ++cnt[rt];
            ans = rt;
        }
        else if(val[rt] > x) ans = insert(lc[rt], x);
        else ans = insert(rc[rt], x);
        update(rt);
        push_down(rt);
        return ans;
    }

    void insert(int x) {
        int rt = insert(root, x);
        splay(rt);
    }

    int id(int& rt, int x) {
        if(rt == 0) return 0;
        push_down(rt);
        if(size[lc[rt]] >= x) return id(lc[rt], x);
        else if(size[lc[rt]] + cnt[rt] >= x) return rt;
        else return id(rc[rt], x - size[lc[rt]] - cnt[rt]);
    }

    void print(int& rt) {
        if(rt == 0) return;
        push_down(rt);
        print(lc[rt]);
        if(abs(val[rt]) != INF)
            for(int i = 1;i<=cnt[rt];i++) cout<<val[rt]<<" ";
        print(rc[rt]);
    }
    void reverse(int l, int r) {
        ++l, ++r;
        int p = id(root, l - 1);
        splay(p);
        int s = id(root, r + 1);
        splay(s, p);
        lazy[lc[s]] ^= 1;
    }
} bs;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    bs.insert(-INF);
    for(int i = 1;i<=n;i++) {
        bs.insert(i);
    }
    bs.insert(INF);
    while(m--) {
        int l, r;
        cin>>l>>r;
        bs.reverse(l, r);
    }
    bs.print(bs.root);
    return 0;
}
