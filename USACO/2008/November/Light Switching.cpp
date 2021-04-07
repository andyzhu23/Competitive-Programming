#include <iostream>
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
int st[N << 2], lazy[N << 2];

inline void push_up(int rt){
    st[rt] = st[rt << 1] + st[rt << 1 | 1];
}

inline void push_down(int rt, int l, int r, int mid){
    if(lazy[rt] == 1){
        st[rt << 1] = (mid - l + 1) - st[rt << 1];
        st[rt << 1 | 1] = (r - mid) - st[rt << 1 | 1];
    }
    lazy[rt << 1] = (lazy[rt << 1] + lazy[rt]) % 2;
    lazy[rt << 1 | 1] = (lazy[rt << 1 | 1] + lazy[rt]) % 2;
    lazy[rt] = 0;
}

inline void update(int rt, int l, int r, int x, int y){
    if(l == x && y == r){
        st[rt] = (r - l + 1) - st[rt];
        lazy[rt] = !lazy[rt];
        return;
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r, mid);
    if(y <= mid) update(rt << 1, l, mid, x, y);
    else if(x > mid) update(rt << 1 | 1, mid + 1, r, x, y);
    else update(rt << 1, l, mid, x, mid), update(rt << 1 | 1, mid + 1, r, mid + 1, y);
    push_up(rt);

}

inline int query(int rt, int l, int r, int x, int y){
    if(l == x && y == r){
        return st[rt];
    }
    int mid = (l + r) >> 1;
    push_down(rt, l, r, mid);
    if(y <= mid) return query(rt << 1, l, mid, x, y);
    else if(x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    else return query(rt << 1, l, mid, x, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, y);
}

int n, m;

inline void solve(){
    int opt, a, b;
    cin>>opt>>a>>b;
    if(opt){
        cout<< query(1, 1, n, a, b)<<endl;
    } else {
        update(1, 1, n, a, b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        solve();
    }
    return 0;
}
