#include <iostream>
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
struct node{
    int lx, rx, mx;
};
node st[N << 2];
int n, m, a[N];

void push_up(int rt, int l, int r, int mid){
    st[rt].lx = st[rt << 1].lx;
    st[rt].rx = st[rt << 1 | 1].rx;
    if(st[rt << 1].lx == mid - l + 1 && a[mid] < a[mid + 1]){
        st[rt].lx += st[rt << 1 | 1].lx;
    }
    if(st[rt << 1 | 1].rx == r - mid && a[mid] < a[mid + 1]){
        st[rt].rx += st[rt << 1].rx;
    }
    st[rt].mx = 0;
    if(a[mid] < a[mid + 1]) {
        st[rt].mx = st[rt << 1].rx + st[rt << 1 | 1].lx;
    }
    st[rt].mx = max(st[rt].mx, max(st[rt << 1].mx, st[rt << 1 | 1].mx));
}

void build(int rt, int l, int r){
    if(l == r){
        st[rt].mx = 1;
        st[rt].rx = st[rt].lx = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt, l, r, mid);
}

node query(int rt, int l, int r, int x, int y){
    if(l == x && y == r){
        return st[rt];
    }
    int mid = (l + r) >> 1;
    if(y <= mid) return query(rt << 1, l, mid, x, y);
    else if(mid < x) return query(rt << 1 | 1, mid + 1, r, x, y);
    else {
        node c = query(rt << 1, l, mid, x, mid);
        node d = query(rt << 1 | 1, mid + 1, r, mid + 1, y);
        node e;
        e.lx = c.lx;
        e.rx = d.rx;
        if(c.lx == mid - x + 1 && a[mid] < a[mid + 1]){
            e.lx += d.lx;
        }
        if(d.rx == y - mid && a[mid] < a[mid + 1]){
            e.rx += c.rx;
        }
        e.mx = 0;
        if(a[mid] < a[mid + 1]) {
            e.mx = c.rx + d.lx;
        }
        e.mx = max(e.mx, max(c.mx, d.mx));
        return e;
    }
}

void update(int rt, int l, int r, int pos, int val){
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    push_up(rt, l, r, mid);
}

void solve(){
    char c;
    int A, B;
    cin>>c>>A>>B;
    if(c == 'Q'){
        cout<<query(1 ,1 ,n, A, B).mx<<endl;
    } else {
        a[A] = B;
        update(1, 1, n, A, B);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    build(1, 1, n);
    while(m --){
        solve();
    }
    return 0;
}
