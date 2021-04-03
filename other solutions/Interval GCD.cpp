#include <iostream>
#include <cstdio>
#define int ll
using namespace std;
typedef long long ll;
const int N = 1e7 + 10;
ll st1[N << 2], st2[N << 2], lazy1[N << 2];
ll a[N];

inline int getMid(int l, int r){
    return (l + r) >> 1;
}

inline void push_up1(int rt){
    st1[rt] = st1[rt << 1] + st1[rt << 1 | 1];
}

inline void push_down1(int rt, int mid, int l, int r){
    lazy1[rt << 1] += lazy1[rt];
    lazy1[rt << 1 | 1] += lazy1[rt];
    st1[rt << 1] += (mid - l + 1) * lazy1[rt];
    st1[rt << 1 | 1] += (r - mid) * lazy1[rt];
    lazy1[rt] = 0;
}

inline void build1(int rt, int l, int r){
    if(l == r){
        st1[rt] = a[l];
        return;
    }
    int mid = getMid(l, r);
    build1(rt << 1, l, mid);
    build1(rt << 1 | 1, mid + 1, r);
    push_up1(rt);
}

inline void update1(int rt, int l, int r, int x, int y, ll val){
    if(l == x && y == r){
        st1[rt] += (r - l + 1) * val;
        lazy1[rt] += val;
        return;
    }
    int mid = getMid(l, r);
    push_down1(rt, mid, l, r);
    if(y <= mid) update1(rt << 1, l, mid, x, y, val);
    else if(x > mid) update1(rt << 1 | 1, mid + 1, r, x, y, val);
    else update1(rt << 1, l, mid, x, mid, val), update1(rt << 1 | 1, mid + 1, r, mid + 1, y, val);
    push_up1(rt);
}

inline ll query1(int rt, int l, int r, int pos){
    if(l == r){
        return st1[rt];
    }
    int mid = getMid(l, r);
    push_down1(rt, mid, l, r);
    if(pos <= mid) return query1(rt << 1, l, mid, pos);
    else return query1(rt << 1 | 1, mid + 1, r, pos);
}

inline ll getGCD(ll a, ll b){
    if(b == 0) return a;
    return getGCD(b, a % b);
}

inline void push_up2(int rt){
    st2[rt] = getGCD(st2[rt << 1], st2[rt << 1 | 1]);
}

inline void build2(int rt, int l, int r){
    if(l == r){
        st2[rt] = a[r] - a[r - 1];
        return;
    }
    int mid = getMid(l, r);
    build2(rt << 1, l, mid);
    build2(rt << 1 | 1, mid + 1, r);
    push_up2(rt);
}

inline void update2(int rt, int l, int r, int pos, ll val){
    if(l == r){
        st2[rt] += val;
        return;
    }
    int mid = getMid(l, r);
    if(pos <= mid) update2(rt << 1, l, mid, pos, val);
    else update2(rt << 1 | 1, mid + 1, r, pos, val);
    push_up2(rt);
}

inline ll query2(int rt, int l, int r, int x, int y){
    if(l == x && y == r){
        return st2[rt];
    }
    int mid = getMid(l, r);
    if(y <= mid) return query2(rt << 1, l, mid, x, y);
    else if(x > mid) return query2(rt << 1 | 1, mid + 1, r, x, y);
    else return getGCD(query2(rt << 1, l, mid, x, mid), query2(rt << 1 | 1, mid + 1, r, mid + 1, y));
}

int n, m;

inline void solve(){
    char c;
    int a, b;
    scanf(" %c %lld %lld", &c, &a, &b);
    if(c == 'Q'){
        if(a == b) printf("%lld\n", query1(1, 1, n, a));
        else printf("%lld\n", getGCD(query1(1, 1, n, a), abs(query2(1, 1, n, a + 1, b)))); 
      // compute absolute value after calculation to avoid mistakes when updating
    } else {
        ll val;
        scanf("%lld", &val);
        update1(1, 1, n, a, b, val);
        update2(1, 1, n, a, val);
        if(n >= b + 1) update2(1, 1, n, b + 1, -val);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%lld %lld", &n, &m);
    for(int i = 1;i<=n;i++){
        ll x; scanf("%lld", &x);
        a[i] = x;
    }
    build1(1 ,1, n);
    build2(1, 1, n);
    while(m --){
        solve();
    }
    return 0;
}
