#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 1e5 + 10;

template <typename T> struct BST{
    T val[N], lc[N], rc[N], cnt[N], tot, root, size[N], rnd[N];

    T& Find(int& rt, int x) {
        if(rt == 0) return rt;
        if(val[rt] == x) return rt;
        if(val[rt] > x) return Find(lc[rt], x);
        else return Find(rc[rt], x);
    }

    void push_up(int rt) {
        size[rt] = size[lc[rt]] + size[rc[rt]] + cnt[rt];
    }

    void rturn(int& rt) {
        int tmp = lc[rt];
        lc[rt] = rc[lc[rt]];
        rc[tmp] = rt;
        push_up(rt);
        rt = tmp;
        push_up(rt);
    }

    void lturn(int& rt) {
        int tmp = rc[rt];
        rc[rt] = lc[rc[rt]];
        lc[tmp] = rt;
        push_up(rt);
        rt = tmp;
        push_up(rt);
    }

    void insert(int& rt, int x) {
        if(rt == 0) {
            rt = ++tot;
            size[rt] = 1;
            val[rt] = x;
            cnt[rt] = 1;
            rnd[rt] = rand();
            return;
        }
        if(val[rt] == x) cnt[rt] ++;
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

    int succans;
    void succ(int& rt, int x) {
        if(rt == 0) return;
        if(val[rt] > x) {
            succans = val[rt];
            succ(lc[rt], x);
        } else succ(rc[rt], x);
    }

    int preans;
    void pre(int& rt, int x) {
        if(rt == 0) return;
        if(val[rt] < x) {
            preans = val[rt];
            pre(rc[rt], x);
        } else pre(lc[rt], x);
    }

    void erase(int& rt, int x) {
        if(rt == 0) return;
        if(val[rt] == x) {
            if(cnt[rt] - 1 == 0) {
                if(lc[rt] * rc[rt] == 0) rt = lc[rt] + rc[rt];
                else {
					if(rnd[lc[rt]] > rnd[rc[rt]]) rturn(rt);
                    else lturn(rt);
                    erase(rt, x);
                }
            } else cnt[rt]--;
        } 
        else if(val[rt] > x) erase(lc[rt], x);
        else erase(rc[rt], x);
        push_up(rt);
    }

    int rnk(int& rt, int x) {
        if(rt == 0) return 1;
        if(val[rt] == x) return size[lc[rt]] + 1; 
        if(val[rt] > x) return rnk(lc[rt], x);
        else return rnk(rc[rt], x) + size[lc[rt]] + cnt[rt];
    }

    int id(int& rt, int x) {
        if(rt == 0) return 0;
        if(size[lc[rt]] >= x) return id(lc[rt], x);
        else if(size[lc[rt]] + cnt[rt] >= x) return val[rt];
        else return id(rc[rt], x - size[lc[rt]] - cnt[rt]);
    }
    void print(int rt){
    	if(rt == 0) return;
    	printf("id: %d, rt:%d, lc:%d, rc:%d, sz:%d, cnt:%d\n", rt, val[rt], lc[rt], rc[rt], size[rt], cnt[rt]);
    	print(lc[rt]);
    	print(rc[rt]);
    }
};

BST<int> bst;
int n, a[N];
map<int, int> id;

int main(){
    srand(time(NULL));
    cin>>n;
    for(int i = 1;i<=n;i++) {
        int opt, x;
        cin>>opt>>x;
        if(opt == 1) bst.insert(bst.root, x);
        else if(opt == 2) bst.erase(bst.root, x);
        else if(opt == 3) cout<<bst.rnk(bst.root, x)<<'\n';
        else if(opt == 4) cout<<bst.id(bst.root, x)<<'\n';
        else if(opt == 5) {
            bst.pre(bst.root, x);
            cout<<bst.preans<<'\n';
        }
        else {
            bst.succ(bst.root, x);
            cout<<bst.succans<<'\n';
        }
    }
    return 0;
}

