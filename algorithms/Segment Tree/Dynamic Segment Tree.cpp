#include <iostream>
#define endl "\n"
#define int long long
using namespace std;
using ll = long long;
const int N = 1e7 + 10;
const ll INF = 1e18 + 10;
int n;
struct node{
    int l, r;
    ll val;
} st[N];
int tot = 0;

inline void push_up(int rt){
    st[rt].val = st[st[rt].l].val + st[st[rt].r].val;
}

inline int query(int &rt, int l, int r, int x, int y){
    if(!rt) {
        rt = ++tot;
        st[rt].l = st[rt].r = st[rt].val = 0;
    }
    if(l == x && y == r){
        return st[rt].val;
    }
    int mid = (l + r) >> 1;
    if(y <= mid) return query(st[rt].l, l, mid, x, y);
    else if(x > mid) return query(st[rt].r, mid + 1, r, x, y);
    else return query(st[rt].l, l, mid, x, mid) + query(st[rt].r, mid + 1, r, mid + 1, y);
}

inline void update(int& rt, int l, int r, int pos, int val){
    if(!rt) {
        rt = ++tot;
        st[rt].l = st[rt].r = st[rt].val = 0;
    }
    if(l == r){
        st[rt].val = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(st[rt].l, l, mid, pos, val);
    else update(st[rt].r, mid + 1, r, pos, val);
    push_up(rt);
}

int root = 0;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        int x; cin>>x;
        ans += query(root, 1, INF, x + 1, INF);
        update(root, 1, INF, x, 1);
    }
    cout<<ans<<endl;
    return 0;
}
