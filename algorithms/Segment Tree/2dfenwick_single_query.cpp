#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
int n, m;

template <typename T> 
struct fenwick {
    vec<vec<T> > d;

    int n, m;

    template <typename tmp> 
    tmp lowbit(tmp i) {return i & (-i);}

    fenwick(int N, int M) {
        n = N, m = M;
        d = vec<vec<T> >(n + 5);
        for(vec<T>& x : d) x = vec<T>(m + 5);
    }

    T query(int x, int y) {
        T ans = 0;
        for(int i = x;i;i-=lowbit(i)) {
            for(int j = y;j;j-=lowbit(j)) {
                ans += d[i][j];
            }
        }
        return ans;
    }

    void update(int x, int y, T val) {
        for(int i = x; i < d.size(); i += lowbit(i)) {
            for(int j = y; j < d[i].size(); j+= lowbit(j)) {
                d[i][j] += val;
            }
        }
    }

    void update(int a, int b, int c, int d, T val) {
        update(a, b, val);
        update(c + 1, b, -val);
        update(a, d + 1, -val);
        update(c + 1, d + 1, val);
    }
};

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    char opt;
    cin>>opt>>n>>m;
    fenwick<int> st(n, m);
    while(cin>>opt) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if(opt == 'L') {
            int x; cin>>x;
            st.update(a, b, c, d, x);
        } else cout<<st.query(a, b)<<'\n';
    }
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) {
            cout<<st.query(i, j)<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
