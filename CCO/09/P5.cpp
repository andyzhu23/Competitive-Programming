#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q;

struct node {
    int a[5][5];
    void init(int r, int c, int k) {
        int tot = 0;
        vector<vector<int> > b(5, vector<int>(5));
        for(int i = 1;i<=4;++i) {
            for(int j = 1;j<=4;++j) a[i][j] = b[i][j] = ++tot;
        }
        for(int j = c + k - 1;j>c;--j) a[r][j] = b[r][j - 1];
        for(int j = c;j<c + k - 1;++j) a[r + k - 1][j] = b[r + k - 1][j + 1];
        for(int i = r + k - 1;i>r;--i) a[i][c + k - 1] = b[i - 1][c + k - 1];
        for(int i = r;i<r + k - 1;++i) a[i][c] = b[i + 1][c];
    }
    node operator+(const node& o) const {
        node ans;
        for(int i = 1;i<=4;++i) {
            for(int j = 1;j<=4;++j) {
                int ii = (o.a[i][j] - 1) / 4 + 1;
                int jj = (o.a[i][j] - 1) % 4 + 1;
                ans.a[i][j] = a[ii][jj];
            }
        }
        return ans;
    }
};

struct segtree {
    node st[N << 2];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    void build(int rt, int l, int r) {
        if(l == r) {
            int r, c, k;
            cin>>r>>c>>k;
            st[rt].init(r, c, k);
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        st[rt] = st[lc] + st[rc];
    }
    void update(int rt, int l, int r, int pos, int rr, int c, int k) {
        if(l == r) {
            st[rt].init(rr, c, k);
            return;
        }
        int mid = l + r >> 1;
        if(pos <= mid) update(lc, l, mid, pos, rr, c, k);
        else update(rc, mid + 1, r, pos, rr, c, k);
        st[rt] = st[lc] + st[rc];
    }
} st;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>q;
    st.build(1, 1, n);
    while(q--) {
        int pos, r, c, k;
        cin>>pos>>r>>c>>k;
        st.update(1, 1, n, pos, r, c, k);
        for(int i = 1;i<=4;++i) {
            for(int j = 1;j<=4;++j) {
                cout<<st.st[1].a[i][j]<<" \n"[j==4];
            }
        }
    }
    return 0;
}
