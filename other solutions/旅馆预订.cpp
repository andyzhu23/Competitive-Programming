#include <iostream>
#include <memory.h>
#define endl "\n"
using namespace std;
const int N = 5e5 + 10;
int n, m;
int lazy[N << 2];

struct node{
   int lx, rx, mx;
} st[N << 2];

inline void push_up(int rt, int l, int r, int mid){
    st[rt].lx = st[rt << 1].lx;
    st[rt].rx = st[rt << 1 | 1].rx;
    st[rt].mx = st[rt << 1].rx + st[rt << 1 | 1].lx;
    if(st[rt].lx == mid - l + 1) st[rt].lx += st[rt << 1 | 1].lx;
    if(st[rt].rx == r - mid) st[rt].rx += st[rt << 1].rx;
    st[rt].mx = max(st[rt].mx, max(st[rt << 1].mx, st[rt << 1 | 1].mx));
}

inline void push_down(int rt, int l, int r, int mid){
    if(lazy[rt] == 1){
        st[rt << 1].lx = st[rt << 1].rx = st[rt << 1].mx = st[rt << 1 | 1].lx = st[rt << 1 | 1].rx = st[rt << 1 | 1].mx = 0;
        lazy[rt << 1] = lazy[rt << 1 | 1] = 1;
    } else if(lazy[rt] == 0){
        st[rt << 1].lx = st[rt << 1].rx = st[rt << 1].mx = mid - l + 1;
        st[rt << 1 | 1].lx = st[rt << 1 | 1].rx = st[rt << 1 | 1].mx = r - mid;
        lazy[rt << 1] = lazy[rt << 1 | 1] = 0;
    }
    lazy[rt] = -1;
}

inline void build(int rt, int l, int r){
    if(l == r){
        st[rt].lx = st[rt].rx = st[rt].mx = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt, l, r, mid);
}

inline void update(int rt, int l, int r, int x, int y, int val){
    if(l == x && y == r){
        if(val == 1) {
            st[rt].lx = st[rt].rx = st[rt].mx = 0;
            lazy[rt] = 1;
        } else {
            st[rt].lx = st[rt].rx = st[rt].mx = r - l + 1;
            lazy[rt] = 0;
        }
        return;
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r, mid);
    if(y <= mid) update(rt << 1, l, mid, x, y, val);
    else if(x > mid) update(rt << 1 | 1, mid + 1, r, x, y, val);
    else update(rt << 1, l, mid, x, mid, val), update(rt << 1 | 1, mid + 1, r, mid + 1, y, val);
    push_up(rt, l, r, mid);
}

inline int query(int rt, int l, int r, int x){
    if(st[rt].mx >= x){
        int mid = (l + r) >> 1;
        push_down(rt, l, r, mid);
        if(st[rt << 1].mx >= x) return query(rt << 1, l, mid, x);
        else if(st[rt << 1].rx + st[rt << 1 | 1].lx >= x) return mid - st[rt << 1].rx + 1;
        else return query(rt << 1 | 1, mid + 1, r, x);
    } else return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(lazy, -1, sizeof(lazy));
    cin>>n>>m;
    build(1, 1, n);
    while(m --){
        int opt;
        cin>>opt;
        if(opt == 1){
            int x; cin>>x;
            int ans = query(1, 1, n, x);
            if(ans != 0) update(1, 1, n, ans, ans + x - 1, 1);
            cout<<ans<<endl;
        } else {
            int x, y; cin>>x>>y;
            update(1, 1, n, x, x + y - 1, 0);
        }
    }
    return 0;
}
