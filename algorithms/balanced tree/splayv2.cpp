#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct SPLAY {
    int size[N], fa[N], lc[N], rc[N], val[N], cnt[N], root, tot;
#define chk(rt) (rc[fa[rt]] != rt)

    void update(int rt) {
        size[rt] = size[lc[rt]] + size[rc[rt]] + cnt[rt];
        fa[lc[rt]] = fa[rc[rt]] = rt;
    }
    void turn(int x) {
        int y = fa[x];
        int z = fa[y];
        int tmp;
        if(chk(x)) {
            // right turn
            tmp = rc[x];
            rc[x] = y;
            lc[y] = tmp;
        } else {
            // left turn
            tmp = lc[x];
            lc[x] = y;
            rc[y] = tmp;
        }
        fa[tmp] = y;
        fa[y] = x;
        fa[x] = z;
        lc[z] == y ? lc[z] = x : rc[z] = x;
        update(y);
        update(x);
    }

    void splay(int rt) {
        while(fa[rt]) {
            if(fa[fa[rt]]) {
                if(chk(fa[rt]) == chk(rt)) turn(fa[rt]);
                else turn(rt);
            }
            turn(rt);
        }
        root = rt;
    }

    void insert(int& rt, int x) {
        if(rt == 0) {
            rt = ++tot;
            size[rt] = 1;
            cnt[rt] = 1;
            val[rt] = x;
            return;
        } else if(val[rt] == x) cnt[rt]++;
        else if(val[rt] > x) insert(lc[rt], x);
        else insert(rc[rt], x);
        update(rt);
    }

    int Find(int& rt, int x) {
        if(rt == 0) return -1;
        if(val[rt] == x) {
            splay(rt);
            return root;
        }
        else if(val[rt] > x) return Find(lc[rt], x);
        else return Find(rc[rt], x);
    }

    int preans;
    void pre(int& rt, int x) {
        if(rt == 0) return;
        if(val[rt] < x) {
            preans = rt;
            pre(rc[rt], x);
        } else pre(lc[rt], x);
    }

    int succans;
    void succ(int& rt, int x) {
        if(rt == 0) return;
        if(val[rt] > x) {
            succans = rt;
            succ(lc[rt], x);
        } else succ(rc[rt], x);
    }

    int rnk(int& rt, int x) {
        if(rt == 0) return 0;
        if(val[rt] == x) return size[lc[rt]] + 1;
        else if(val[rt] > x) return rnk(lc[rt], x);
        else return rnk(rc[rt], x) + size[lc[rt]] + cnt[rt];
    }

    int id(int& rt, int x) {
        if(rt == 0) return 0;
        if(size[lc[rt]] >= x) return id(lc[rt], x);
        else if(size[lc[rt]] + cnt[rt] >= x) return val[rt];
        else return id(rc[rt], x - size[lc[rt]] - cnt[rt]);
    }

    int Max(int& rt) {
        if(rc[rt]) return Max(rc[rt]);
        else return rt;
    }

    int join(int& x, int& y) {
        if(x * y == 0) return x + y;
        int rt = Max(x);
        splay(rt);
        root = rt;
        rc[rt] = y;
        fa[y] = rt;
        update(root);
        return rt;
    }

    void erase(int x) {
        int rt = Find(root, x);
        if(rt == -1 || !rt) return;
        if(--cnt[rt] > 0) {
            update(rt);
            return;
        }
        root = join(lc[rt], rc[rt]);
        fa[root] = 0;
    }

    
    void print(int rt){
        if(rt == 0) return;
        printf("rt: %d, val:%d, lc:%d, rc:%d, sz:%d, cnt:%d, father:%d\n", rt, val[rt], lc[rt], rc[rt], size[rt], cnt[rt], fa[rt]);
        print(lc[rt]);
        print(rc[rt]);
    }

} spl;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n;
    cin>>n;
    while(n--) {
        int opt, x;
        cin>>opt>>x;
        if(opt == 1) {
            spl.insert(spl.root, x);
            spl.Find(spl.root, x);
        } else if(opt ==  2) {
            spl.erase(x);
        } else if(opt ==  3) {
            cout<<spl.rnk(spl.root, x)<<'\n';
        } else if(opt ==  4) {
            int ans = spl.id(spl.root, x);
            cout<<ans<<'\n';
            spl.Find(spl.root, ans);
        } else if(opt ==  5) {
            spl.pre(spl.root, x);
            cout<<spl.val[spl.preans]<<'\n';
            spl.Find(spl.root, spl.preans);
        } else if(opt ==  6) {
            spl.succ(spl.root, x);
            cout<<spl.val[spl.succans]<<'\n';
            spl.Find(spl.root, spl.succans);
        }
//         cout<<opt<<" "<<x<<" "<<spl.root<<'\n';
//         spl.print(spl.root);
    }
    return 0;
}
