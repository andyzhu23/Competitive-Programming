#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct BST {
    int lc[N], rc[N], val[N], rnd[N], size[N], cnt[N], root, tot;

    void update(int rt) {
        size[rt] = size[lc[rt]] + size[rc[rt]] + cnt[rt];
    }

    void lturn(int& rt) {
        int tmp = rc[rt];
        rc[rt] = lc[tmp];
        lc[tmp] = rt;
        update(rt);
        rt = tmp;
        update(rt);
    }

    void rturn(int& rt) {
        int tmp = lc[rt];
        lc[rt] = rc[tmp];
        rc[tmp] = rt;
        update(rt);
        rt = tmp;
        update(rt);
    }

    void insert(int& rt, int x) {
        if(rt == 0) {
            rt = ++tot;
            lc[rt] = rc[rt] = 0;
            val[rt] = x;
            cnt[rt] = size[rt] = 1;
            rnd[rt] = rand();
            return;
        } else if(val[rt] == x) ++cnt[rt];
        else if(val[rt] > x) {
            insert(lc[rt], x);
            if(rnd[lc[rt]] > rnd[rt]) rturn(rt);
        }
        else {
            insert(rc[rt], x);
            if(rnd[rc[rt]] > rnd[rt]) lturn(rt);
        }
        update(rt);
    }

    int id(int& rt, int x) {
        if(rt == 0) return -1;
        if(size[lc[rt]] >= x) return id(lc[rt], x);
        else if(size[lc[rt]] + cnt[rt] >= x) return val[rt];
        else return id(rc[rt], x - size[lc[rt]] - cnt[rt]);
    }
} bst;

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int tot = 0;
    while(n--) {
        string opt;
        cin>>opt;
        if(opt == "add") {
            ++tot;
            int x; cin>>x;
            bst.insert(bst.root, x);
        } else {
            int mid = (tot >> 1) + (tot & 1);
            if(mid == 0) {
                cout<<"empty"<<'\n';
                continue;
            }
            cout<<bst.id(bst.root, mid)<<'\n';
        }
    }

    return 0;
}
