#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;

struct BST {
    int val[N], lc[N], rc[N], cnt[N], size[N], root, tot, fa[N];
    queue<int> garbage;
    void push_up(int rt) {
        size[rt] = size[lc[rt]] + size[rc[rt]] + cnt[rt];
        fa[lc[rt]] = fa[rc[rt]] = rt;
    }
    void insert(int& rt, int x) {
        if(rt == 0) {
            if(garbage.empty()) rt = ++tot;
            else {
                rt = garbage.front(); garbage.pop();
            }
            val[rt] = x;
            cnt[rt] ++;
            size[rt] = 1;
            return;
        }
        if(x == val[rt]) cnt[rt] ++;
        else x < val[rt] ? insert(lc[rt], x) : insert(rc[rt], x);
        push_up(rt);
    }

    int lft(int& rt) {
        if(lc[rt] == 0) return rt;
        else return lft(lc[rt]);
    }

    void remove(int& rt, int x) {
        if(rt == 0) return;
        if(val[rt] == x) {
            if(--cnt[rt] == 0) {
                if(lc[rt] * rc[rt] == 0) rt = lc[rt] + rc[rt];
                else {
                    int nxt = lft(rc[rt]);
                    lc[fa[nxt]] = rc[nxt];
                    fa[rc[nxt]] = fa[nxt];
                    lc[nxt] = lc[rt];
                    rc[nxt] = rc[rt];
                    garbage.push(rt);
                    rt = nxt;
                }
            }
        }
        else x < val[rt] ? remove(lc[rt], x) : remove(rc[rt], x);
        push_up(rt);
    }

    int id(int& rt, int x) {
        if(rt == 0) return -1;
        if(size[lc[rt]] >= x) return id(lc[rt], x);
        else if(size[lc[rt]] + cnt[rt] >= x) return val[rt];
        else return id(rc[rt], x - cnt[rt] - size[lc[rt]]);
    }

    int rnk(int& rt, int x) {
        if(rt == 0) return -1;
        if(val[rt] == x) return size[lc[rt]] + 1;
        else return x < val[rt] ? rnk(lc[rt], x) : rnk(rc[rt], x) + size[lc[rt]] + cnt[rt];
    }

    int Find(int rt, int x) {
        if(val[rt] == x) return rt;
        if(val[rt] > x) return Find(lc[rt], x);
        else return Find(rc[rt], x);
    }

} bst;

int n, m;

int main()  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) {
        int x; cin>>x;
        bst.insert(bst.root, x);
    }
    int ans = 0;
    while(m--) {
        char opt;
        int x;
        cin>>opt>>x;
        x ^= ans;
        if(opt == 'I') {
            ++n;
            bst.insert(bst.root, x);
        }
        else if(opt == 'R') {
            --n;
            bst.remove(bst.root, x);
        }
        else if(opt == 'S') {
            ans = bst.id(bst.root, x);
            cout<<ans<<'\n';
        }
        else if(opt == 'L') {
            ans = bst.rnk(bst.root, x);
            cout<<ans<<'\n';
        }
    }
    for(int i = 1;i<=n;i++) {
        cout<<bst.id(bst.root, i)<<" ";
    }
    cout<<'\n';
    return 0;
}
