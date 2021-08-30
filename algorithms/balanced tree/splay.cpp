#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define mp make_pair
const int N = 1e5 + 10;
template <typename T>
class SPLAY {
private:
    T val[N];
    int lc[N], rc[N], fa[N], size[N], cnt[N], tot = 0, root;
    void update(int& rt) {
        size[rt] = size[lc[rt]] + size[rc[rt]] + cnt[rt];
        fa[lc[rt]] = fa[rc[rt]] = rt;
    }

    void turn(int& x, bool opt) {
        int y = fa[x];
        int z = fa[y];
		int tmp = opt ? rc[x] : lc[x]; 
        opt ? rc[x] = y : lc[x] = y;
        fa[y] = x;
        opt ? lc[y] = tmp : rc[y] = tmp;
        fa[tmp] = y;
        fa[x] = z;
        if(opt) {
            if(lc[z] == y) lc[z] = x;
            else rc[z] = x;
        } else {
            if(rc[z] == y) rc[z] = x;
            else lc[z] = x;
        }
        update(y);
        update(x);
    }

    void splay(int& rt) {
        while(fa[rt] != 0) {
            if(fa[fa[rt]] != 0)
                if(lc[fa[fa[rt]]] == fa[rt] && lc[fa[rt]] == rt)
                    turn(fa[rt], 1);
                else if(rc[fa[fa[rt]]] == fa[rt] && rc[fa[rt]] == rt)
                		turn(fa[rt], 0);
                else turn(rt, lc[fa[rt]] == rt);
            turn(rt, lc[fa[rt]] == rt);
        }
        root = rt;
    }

    int Find(int& rt, T x) {
    		if(rt == 0) return 0;
        if(val[rt] == x) return rt;
        else if(val[rt] > x) return Find(lc[rt], x);
        else return Find(rc[rt], x);
    }

    void insert(int& rt, T x) {
        if(rt == 0) {
            rt = ++tot;
            val[rt] = x;
            size[rt] = 1;
            cnt[rt] = 1;
            return;
        } else if(val[rt] == x) cnt[rt] ++;
        else if(val[rt] > x) insert(lc[rt], x);
        else insert(rc[rt], x);
        update(rt);
    }

    int max(int& rt) {
        if(rc[rt] == 0) return rt;
        else return max(rc[rt]);
    }

    int min(int& rt) {
        if(lc[rt] == 0) return rt;
        else return min(lc[rt]);
    }

    int Join(int& x, int& y) {
        if(x * y == 0) return x + y;
        int rt = max(x);
        splay(rt);
        fa[y] = rt;
        rc[rt] = y;
        update(rt);
        return rt;
    }

    pii Split(T x) {
        int rt = Find(root, x);
        return mp(lc[rt], rc[rt]);
    }

    void Erase(T x) {
        int rt = Find(root, x);
        if(!rt) return;
        splay(rt);
        if(--cnt[rt] > 0){
        	update(rt);
        	return;	
		}
        root = Join(lc[rt], rc[rt]);
        fa[root] = 0; 
    }

    int pre;
    T predecessor(int& rt, T x) {
        if(rt == 0) return 0;
        if(val[rt] < x) {
            pre = rt;
            predecessor(rc[rt], x);
        } else predecessor(lc[rt], x);
    }

    int succ;
    T successor(int& rt, T x) {
        if(rt == 0) return 0;
        if(val[rt] > x) {
            succ = rt;
            successor(lc[rt], x);
        } else successor(rc[rt], x);
    }

    int rnk(int& rt, T x) {
        if(rt == 0) return 0;
        if(val[rt] == x) return size[lc[rt]] + 1;
        if(val[rt] > x) return rnk(lc[rt], x);
        else return rnk(rc[rt], x) + size[lc[rt]] + cnt[rt];
    }

    T id(int& rt, int x) {
        if(rt == 0) return 0;
        if(size[lc[rt]] >= x) return id(lc[rt], x);
        else if(size[lc[rt]] + cnt[rt] >= x) return val[rt];
        else return id(rc[rt], x - size[lc[rt]] - cnt[rt]);
    }

public:

    int rnk(T x) {
        return rnk(root, x);
    }

    T id(int x) {
        return id(root, x);
    }

    pii split(T x) {
        return Split(x);
    }

    void erase(T x) {
        Erase(x);
    }

    void insert(T x) {
        insert(root, x);
        int rt = Find(root, x);
        splay(rt);
    }

    T max() {
        int rt = max(root);
        splay(rt);
        return val[rt];
    }

    T min() {
        int rt = min(root);
        splay(rt);
        return val[rt];
    }

    T predecessor(T x) {
        predecessor(root, x);
        splay(pre);
        return val[pre];
    }

    T successor(T x) {
        successor(root, x);
        splay(succ);
        return val[succ];
    }

    void print(int rt){
        if(rt == 0) return;
        printf("rt: %d, val:%d, lc:%d, rc:%d, sz:%d, cnt:%d, father:%d\n", rt, val[rt], lc[rt], rc[rt], size[rt], cnt[rt], fa[rt]);
        print(lc[rt]);
        print(rc[rt]);
    }
};

SPLAY<int> spl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) {
        int opt, x;
        cin>>opt>>x;
        switch (opt) {
            case 1: spl.insert(x); break;
            case 2: spl.erase(x); break;
            case 3: cout<<spl.rnk(x)<<'\n'; break;
            case 4: cout<<spl.id(x)<<'\n'; break;
            case 5: cout<<spl.predecessor(x)<<'\n'; break;
            case 6: cout<<spl.successor(x)<<'\n'; break;
        }
    }
    return 0;
}
