#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

namespace fast_io {
    inline int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    inline void read(int& x) {x = read();}
    template<typename T> inline void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
            putchar(x % 10 + '0');
    }
    template<typename T> inline void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;
const int N = 1005;
const int INF = 0x3f3f3f3f;
int m, n, b, a, d, c, sum[N][N], mn[N][N];

inline int get(int a, int b, int c, int d) {
    return sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
}

struct sparse_table {
    int st[10][10][N][N], p[1001];
    inline void init() {
        for(int i = 1;i<=max(n, m);i++) p[i] = log2(i);
        for(int r = 1;r<=n;++r) {
            for(int i = 1;i<=m;++i) st[0][0][r][i] = mn[r][i];
            for(int j = 1;j<=p[m];++j)
                for(int i = 1;i + (1 << j) - 1<=m;++i)
                    st[0][j][r][i]= min(st[0][j - 1][r][i], st[0][j - 1][r][i + (1 << (j - 1))]);
        }
        for(int j = 1;j<=p[n];++j)
            for(int i = 1;i + (1 << j) - 1<=n;++i)
                for(int k = 0;k<=p[m];++k)
                    for(int l = 1;l + (1 << k) - 1<=m;++l)
                        st[j][k][i][l] = min(st[j - 1][k][i][l], st[j - 1][k][i + (1 << (j - 1))][l]);
    }
    inline int query(int a, int b, int c, int d) {
        int x = p[c - a + 1];
        int y = p[d - b + 1];
        return min({
            st[x][y][a][b],
            st[x][y][c - (1 << x) + 1][b],
            st[x][y][a][d - (1 << y) + 1],
            st[x][y][c - (1 << x) + 1][d - (1 << y) + 1]
        });
    }
} st;

template <typename T> inline void ckmax(T& a, T b) { a = max(a, b); }

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(m), read(n), read(b), read(a), read(d), read(c);
    for(int i = 1;i<=n;++i) 
        for(int j = 1;j<=m;++j) 
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + read();
    for(int i = 1;i<=n - c + 1;++i) 
        for(int j = 1;j<=m - d + 1;++j) 
            mn[i][j] = get(i, j, i + c - 1, j + d - 1);
    st.init();
    int ans = 0;
    for(int i = 1;i<=n - a + 1;++i) 
        for(int j = 1;j<=m - b + 1;++j) {
            int k = i + a - 1;
            int l = j + b - 1;
            ckmax(ans, get(i, j, k, l) - st.query(i + 1, j + 1, k - c, l - d));
        }
    print(ans, '\n');
    return 0;
}
