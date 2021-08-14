#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

struct BST {
    int lc[N], rc[N], val[N], size[N], rnd[N], cnt[N], root, tot;

    void push_up(int rt) {
        size[rt] = size[lc[rt]] + size[rc[rt]] + cnt[rt];
    }

    int Find(int& rt, int x) {
        if(val[rt] == x) return rt;
        else return val[rt] > x ? Find(lc[rt], x) : Find(rc[rt], x);
    }

    void lturn(int& rt) {
        int tmp = rc[rt];
        rc[rt] = lc[tmp];
        lc[tmp] = rt;
        push_up(rt);
        rt = tmp;
        push_up(rt);
    }

    void rturn(int& rt) {
        int tmp = lc[rt];
        lc[rt] = rc[tmp];
        rc[tmp] = rt;
        push_up(rt);
        rt = tmp;
        push_up(rt);
    }

    void insert(int& rt, int x) {
        if(rt == 0) {
            rt = ++tot;
            size[rt] = 1;
            cnt[rt] = 1;
            val[rt] = x;
            rnd[rt] = rand();
            return;
        }
        else if(val[rt] == x) ++cnt[rt];
        else if(val[rt] > x) {
            insert(lc[rt], x);
            if(rnd[lc[rt]] > rnd[rt]) rturn(rt);
        } else if(val[rt] < x) {
            insert(rc[rt], x);
            if(rnd[rc[rt]] > rnd[rt]) lturn(rt);
        }
        push_up(rt);
    }

    void erase(int& rt, int x) {
        if(rt == 0) return;
        if(val[rt] == x) {
            if(cnt[rt] - 1 == 0) {
                if(lc[rt] * rc[rt] == 0) rt = lc[rt] + rc[rt];
                else {
                    rnd[lc[rt]] > rnd[rc[rt]] ? rturn(rt) : lturn(rt);
                    erase(rt, x);
                } 
            } else cnt[rt] --;
        } else val[rt] > x ? erase(lc[rt], x) : erase(rc[rt], x);
        push_up(rt);
    }

    int id(int& rt, int x) {
        if(rt == 0) return 0;
        if(size[lc[rt]] >= x) return id(lc[rt], x);
        else return size[lc[rt]] + cnt[rt] >= x ? val[rt] : id(rc[rt], x - size[lc[rt]] - cnt[rt]);
    }

    int rnk(int& rt, int x) {
        if(rt == 0) return -1;
        if(val[rt] == x) return size[lc[rt]] + 1;
        if(val[rt] > x) return rnk(lc[rt], x);
        else {
            int res = rnk(rc[rt], x);
            return res == -1 ? -1 : res + size[lc[rt]] + cnt[rt];
        }
    }
    
    void print(int& rt) {
        if(lc[rt]) print(lc[rt]);
        while(cnt[rt]--) cout<<val[rt]<<" ";
        if(rc[rt]) print(rc[rt]);
    }

} bst;

int n, m, ans;

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) {
        int x; cin>>x;
        bst.insert(bst.root, x);
    }
    while(m--) {
        int x;
        char opt;
        cin>>opt>>x;
        x ^= ans;
        switch(opt) {
            case 'I':
                bst.insert(bst.root, x);
                break;
            case 'R':
                bst.erase(bst.root, x);
                break;
            case 'S':
                ans = bst.id(bst.root, x);
                cout<<ans<<'\n';
                break;
            case 'L':
                ans = bst.rnk(bst.root, x);
                cout<<ans<<'\n';
                break;
        }
    }
    bst.print(bst.root);
    return 0;
}
