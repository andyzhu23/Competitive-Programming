#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

template <typename T> struct BST {
    int lc[N], rc[N], sz[N], rnd[N], cnt[N], root, tot;
    T val[N];

    void push_up(int rt) {
        sz[rt] = sz[lc[rt]] + sz[rc[rt]] + cnt[rt];
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

    void insert(int& rt, T x) {
        if(rt == 0) {
            rt = ++tot;
            val[rt] = x;
            cnt[rt] = 1;
            sz[rt] = 1;
            rnd[rt] = rand();
            return;
        } else if(val[rt] == x) cnt[rt] ++;
        else if(val[rt] > x) {
            insert(lc[rt], x);
            if(rnd[lc[rt]] > rnd[rt]) rturn(rt);
        }
        else {
            insert(rc[rt], x);
            if(rnd[rc[rt]] > rnd[rt]) lturn(rt);
        }
        push_up(rt);
    }

    void erase(int& rt, T x) {
        if(rt == 0) return;
        if(val[rt] == x) {
            if(cnt[rt] - 1 == 0) {
                if(lc[rt] * rc[rt] == 0) rt = lc[rt] + rc[rt];
                else {
                    if(rnd[lc[rt]] > rnd[rc[rt]]) rturn(rt);
                    else lturn(rt);
                    erase(rt, x);
                }
            } else cnt[rt] --;
        } else if(val[rt] > x) erase(lc[rt], x);
        else erase(rc[rt], x);
        push_up(rt);
    }

    int Find(int& rt, T x) {
        if(val[rt] == x) return rt;
        else if(val[rt] > x) return Find(lc[rt], x);
        else return Find(rc[rt], x);
    }

    int rnk(int& rt, T x) {
        if(rt == 0) return -1;
        if(val[rt] == x) return sz[lc[rt]] + 1;
        else if(val[rt] > x) return rnk(lc[rt], x);
        int tmp = rnk(rc[rt], x);
        return tmp == -1 ? -1 : tmp + sz[lc[rt]] + cnt[rt];
    }

    T id(int& rt, int x) {
        if(rt == 0) return -1;
        if(sz[lc[rt]] >= x) return id(lc[rt], x);
        else if(sz[lc[rt]] + cnt[rt] >= x) return val[rt];
        else return id(rc[rt], x - sz[lc[rt]] - cnt[rt]);
    }

    T succans;
    void succ(int& rt, T x) {
        if(rt == 0) return;
        if(val[rt] > x) {
            succans = val[rt];
            succ(lc[rt], x);
        } else succ(rc[rt], x);
    }
    
    T preans;
    void pre(int& rt, T x) {
        if(rt == 0) return;
        if(val[rt] < x) {
            preans = val[rt];
            pre(rc[rt], x);
        } else pre(lc[rt], x);
    }

    void debug(int rt){
    	if(rt == 0) return;
        cout<<"rt: "<<val[rt]<<" ";
    	printf("id: %d, lc:%d, rc:%d, sz:%d, cnt:%d, val:\n", rt, lc[rt], rc[rt], sz[rt], cnt[rt]);
    	debug(lc[rt]);
    	debug(rc[rt]);
	}

    void print(int& rt, int x) {
        if(rt == 0) return;
        print(lc[rt], x);
        for(int i = 0;i<cnt[rt];i++)
            cout<<val[rt]<<' ';
        print(rc[rt], x);
    }

};

BST<int> bst;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--) {
        int opt, x;
        cin>>opt>>x;
        switch (opt) {
            case 1:
                bst.insert(bst.root, x);
                break;
            case 2:
                bst.erase(bst.root, x);
                break;
            case 3:
                cout<<bst.rnk(bst.root, x)<<'\n';
                break;
            case 4:
                cout<<bst.id(bst.root, x)<<'\n';
                break;
            case 6:
                bst.succ(bst.root, x);
                cout<<bst.succans<<'\n';
                break;
            case 5:
                bst.pre(bst.root, x);
                cout<<bst.preans<<'\n';
                break;
        }
    }

    return 0;
}
