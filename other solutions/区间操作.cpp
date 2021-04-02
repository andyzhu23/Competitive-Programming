#include <iostream>
#define getMid(l, r) (l + r) >> 1
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll st[N << 2];
bool flag[N << 2];

inline void push_up(int rt){
    st[rt] = st[rt << 1] + st[rt << 1 | 1];
    flag[rt] = flag[rt << 1] && flag[rt << 1 | 1];
}

inline void build(int rt, int l, int r){
    if(l == r){
        scanf("%lld", &st[rt]);
        if(st[rt] == 0) flag[rt] = true;
        else flag[rt] = false;
        return;
    }
    int mid = getMid(l, r);
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}

inline void update1(int rt, int l, int r, int x, int y, int k){
    if(flag[rt]) return;
    if(l == r){
        st[rt] /= k;
        if(st[rt] == 0) flag[rt] = true;
        else flag[rt] = false;
        return;
    }
    int mid = getMid(l, r);
    if(y <= mid) update1(rt << 1, l, mid, x, y, k);
    else if(x > mid) update1(rt << 1 | 1, mid + 1, r, x, y, k);
    else update1(rt << 1, l, mid, x, mid, k), update1(rt << 1 | 1, mid + 1, r, mid + 1, y, k);
    push_up(rt);
}

inline void update2(int rt, int l, int r, int pos, int val){
    if(l == r){
        st[rt] = val;
        if(st[rt] == 0) flag[rt] = true;
        else flag[rt] = false;
        return;
    }
    int mid = getMid(l, r);
    if(pos <= mid) update2(rt << 1, l, mid, pos, val);
    else update2(rt << 1 | 1, mid + 1, r, pos, val);
    push_up(rt);
}

inline ll query(int rt, int l, int r, int x, int y){
    if(l == x && r == y){
        return st[rt];
    }
    int mid = getMid(l, r);
    if(y <= mid) return query(rt << 1, l, mid, x, y);
    else if(x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    else return query(rt << 1, l, mid, x, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, y);
}

int n, m;
inline void solve(){
    int opt, a, b;
    scanf("%d %d %d", &opt, &a, &b);
    a++, b++;
    if(opt == 0){
        int k;
        scanf("%d", &k);
        update1(1, 1, n, a, b, k);
    } else if(opt == 1){
        b--;
        update2(1, 1, n, a, b);
    } else {
        printf("%lld\n", query(1, 1, n, a, b));
    }
}

int main() {
    scanf("%d %d", &n, &m);
    build(1, 1, n);
    while(m--){
        solve();
    }
    return 0;
}
