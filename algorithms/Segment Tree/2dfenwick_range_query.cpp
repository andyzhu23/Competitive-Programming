#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;

template <typename T> 
struct fenwick {
    int n, m;
    template <typename T2> using vec = vector<T2>;
    template <typename T2> T2 lowbit(T2 i) {return i & (-i);}
    vec<vec<T> > d, di, dj, dij;
    fenwick(int N, int M) {
        n = N + 10, m = M + 10;
        d = vec<vec<T> >(n);
        di = vec<vec<T> >(n);
        dj = vec<vec<T> >(n);
        dij = vec<vec<T> >(n);
        for(int i = 0;i<n;++i) {
            d[i] = vec<T>(m);
            di[i] = vec<T>(m);
            dj[i] = vec<T>(m);
            dij[i] = vec<T>(m);
        }
    }

    void update(int x, int y, T val) {
        for(int i = x; i < n; i += lowbit(i)) {
            for(int j = y; j < m; j += lowbit(j)) {
                d[i][j] += val;
                di[i][j] += val * x;
                dj[i][j] += val * y;
                dij[i][j] += val * x * y;
            }
        }
    }

    void update(int x, int y, int x2, int y2, T val) {
        update(x, y, val);
        update(x, y2 + 1, -val);
        update(x2 + 1, y, -val);
        update(x2 + 1, y2 + 1, val);
    }

    T query(int x, int y) {
        if(x * y == 0) return 0;
        T ans = 0;
        for(int i = x;i; i -= lowbit(i)) {
            for(int j = y;j; j -= lowbit(j)) {
                ans += (x + 1) * (y + 1) * d[i][j] - (x + 1) * dj[i][j] - (y + 1) * di[i][j] + dij[i][j];
            }
        }
        return ans;
    }

    T query(int x, int y, int x2, int y2) {
        return query(x2, y2) + query(x - 1, y - 1) - query(x2, y - 1) - query(x - 1, y2);
    }
};

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    char opt;
    cin>>opt>>n>>m;
    fenwick<ll> st(n, m);
    while(cin>>opt) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if(opt == 'L') {
            int x; cin>>x;
            st.update(a, b, c, d, x);
        } else cout<<st.query(a, b, c, d)<<'\n';
    }
    return 0;
}
