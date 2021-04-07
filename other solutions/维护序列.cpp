#include <iostream>
#define endl "\n"
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int MOD, n, m;
ll st[N << 2], lazy2[N<<2], lazy1[N << 2];

inline int getMid(int l, int r){
    return (l + r) >> 1;
}

inline void push_up(int rt){
    st[rt] = (st[rt << 1] + st[rt << 1 | 1]) % MOD;
}

inline void push_down(int rt, int mid, int l, int r){
    st[rt << 1] = (st[rt << 1] * lazy1[rt] + (mid - l + 1) * lazy2[rt]) % MOD;
    st[rt << 1 | 1] = (st[rt << 1 | 1] * lazy1[rt] + (r - mid) * lazy2[rt]) % MOD;
    lazy2[rt << 1 | 1] = (lazy2[rt << 1 | 1] * lazy1[rt] + lazy2[rt]) % MOD;
    lazy2[rt << 1] = (lazy2[rt << 1] * lazy1[rt] + lazy2[rt]) % MOD;
    lazy1[rt << 1] *= lazy1[rt] % MOD;
    lazy1[rt << 1 | 1] *= lazy1[rt] % MOD;
    lazy1[rt << 1] %= MOD;
    lazy1[rt << 1 | 1] %= MOD;
    lazy2[rt] = 0;
    lazy1[rt] = 1;
}

inline void build(int rt, int l, int r){
    if(l == r){
        cin>>st[rt];
        st[rt] %= MOD;
        return;
    }
    int mid = getMid(l, r);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}

inline void update1(int rt, int l, int r, int x, int y, ll val){
    if(l == x && y == r){
        lazy1[rt] *= val % MOD;
        lazy1[rt] %= MOD;
        st[rt] = (st[rt] % MOD) * (val % MOD) % MOD;
        lazy2[rt] *= val % MOD;
        lazy2[rt] %= MOD;
        return;
    }
    int mid = getMid(l, r);
    push_down(rt, mid, l, r);
    if(y <= mid) update1(rt << 1, l, mid, x, y, val);
    else if(x > mid) update1(rt << 1 | 1, mid + 1, r, x, y,val);
    else update1(rt << 1, l, mid, x, mid, val), update1(rt << 1 | 1, mid + 1, r, mid + 1, y, val);
    push_up(rt);
}

inline void update2(int rt, int l, int r, int x, int y, ll val){
    if(l == x && y == r){
        lazy2[rt] += val;
        lazy2[rt] %= MOD;
        st[rt] += (r - l + 1) % MOD * val % MOD;
        return;
    }
    int mid = getMid(l, r);
    push_down(rt, mid, l, r);
    if(y <= mid) update2(rt << 1, l, mid, x, y,val);
    else if(x > mid) update2(rt << 1 | 1, mid + 1, r, x, y,val);
    else update2(rt << 1, l, mid, x, mid, val), update2(rt << 1 | 1, mid + 1, r, mid + 1, y, val);
    push_up(rt);
}

inline ll query(int rt, int l, int r, int x, int y){
    if(l == x && y == r){
        return st[rt];
    }
    int mid = getMid(l, r);
    push_down(rt, mid, l, r);
    if(y <= mid) return query(rt << 1, l, mid, x, y);
    else if(x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    else return (query(rt << 1, l, mid, x, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, y)) % MOD;
}

inline void solve(){
    int opt, t, g, c;
    cin>>opt>>t>>g;
    if(opt == 1){
        cin>>c;
        update1(1,1,n,t,g,c);
    } else if(opt == 2){
        cin>>c;
        update2(1,1,n,t,g,c);
    } else {
        cout<< query(1,1,n,t,g)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1;i< 4 * N;i ++) lazy1[i] = 1;
    cin>>n >>MOD;
    build(1, 1, n);
    cin>>m;
    while(m--){
        solve();
    }
    return 0;
}
