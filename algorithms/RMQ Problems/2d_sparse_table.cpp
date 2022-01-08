#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

struct sparse_table {

    int st[10][10][1001][1001], p[1001];

    void init(std::vector<std::vector<int>> arr) {
        int n = arr.size();
        for(int i = 1;i<=n;i++) p[i] = log2(i);
        for(int r = 0;r<n;++r) {
            for(int i = 0;i<n;++i) st[0][0][r][i] = arr[r][i];
            for(int j = 1;j<=p[n];++j)
                for(int i = 0;i + (1 << j) - 1<n;++i)
                    st[0][j][r][i]= min(st[0][j - 1][r][i], st[0][j - 1][r][i + (1 << (j - 1))]);
        }
        for(int j = 1;j<=p[n];++j)
            for(int i = 0;i + (1 << j) - 1<n;++i)
                for(int k = 0;k<=p[n];++k)
                    for(int l = 0;l + (1 << k) - 1<n;++l)
                        st[j][k][i][l] = min(st[j - 1][k][i][l], st[j - 1][k][i + (1 << (j - 1))][l]);
    }

    int query(int a, int c, int b, int d) {
        int x = p[c - a + 1];
        int y = p[d - b + 1];
        return min({
            st[x][y][a][b],
            st[x][y][c - (1 << x) + 1][b],
            st[x][y][a][d - (1 << y) + 1],
            st[x][y][c - (1 << x) + 1][d - (1 << y) + 1]
        });
    }

};
