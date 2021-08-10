#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define lc rt << 1
#define rc rt << 1 | 1
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int n;
struct hw{
    int a, b, id;
    bool operator<(const hw& other) const {
        if(a != other.a) return a > other.a;
        return b < other.a;
    }
}pos[N];

hw a[N];

template <typename T> struct segtree {
    T st[N << 2];
    void push_up(int rt) {
        st[rt] = st[lc].b > st[rc].b ? st[rc] : st[lc];
    }
    void build(int rt, int l, int r) {
        if(l == r) {
            st[rt] = pos[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        push_up(rt);
    }
    void update(int rt, int l, int r, int pos, T val) {
        if(l == r) {
            st[rt] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) update(lc, l, mid, pos, val);
        else update(rc, mid + 1, r, pos, val);
        push_up(rt);
    }
    T query(int rt, int l, int r, int x, int y) {
        if(l == x && y == r) return st[rt];
        int mid = (l + r) >> 1;
        if(y <= mid) return query(lc, l, mid, x, y);
        else if(x > mid) return query(rc, l, mid, x, y);
        else {
            T lft = query(lc, l, mid, x, mid);
            T rgt = query(rc, mid + 1, r, mid + 1, y);
            return lft.b > rgt.b ? rgt : lft;
        }
    }
};

segtree<hw> st;

priority_queue<hw> heap;


bool cmp(hw a, hw b) {
    return a.a == b.a ? a.b > b.b : a.a < b.a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        hw b;
        cin>>b.a>>b.b;
        a[i - 1] = b;
    }

    sort(a, a + n, cmp);

    int cnt = 1;

    for(int i = 0;i<n;i++) {
        if(a[i].a >= cnt) {
            pos[cnt] = a[i];
            pos[cnt].id = cnt;
            cnt++;
        }
        else heap.push(a[i]);
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) {
        ans += pos[i].b;
    }
    st.build(1, 1, N - 9);
    while(!heap.empty()) {
        hw cur = heap.top(); heap.pop();
        hw Min = st.query(1, 1, N - 9, 1, cur.a);
        if(Min.b >= cur.b) continue;
        heap.push(Min);
        cur.id = Min.id;
        st.update(1, 1, N - 9, Min.id, cur);
        ans = ans - Min.b + cur.b;
    }
    cout<<ans<<"\n";
    return 0;
}
