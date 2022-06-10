#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, d, t[N], p[N];


struct D4 {
    double dp[N][15][15][15][15];
    void solve() {
        for(int i = 1;i<=12;++i) {
            for(int j = i + 1;j<=12;++j) {
                for(int k = j + 1;k<=12;++k) {
                    for(int l = k + 1;l<=12;++l) {
                        dp[0][i][j][k][l] = 2e9;
                    }
                }
            }
        }
        for(int idx = 1;idx<=n;++idx) {
            scanf("%d%d", t + idx, p + idx);
            for(int i = 1;i<=12;++i) {
                for(int j = i + 1;j<=12;++j) {
                    for(int k = j + 1;k<=12;++k) {
                        for(int l = k + 1;l<=12;++l) {
                            if(i != p[idx] && j != p[idx] && k != p[idx] && l != p[idx]) continue;
                            for(int ii = 1;ii<=12;++ii) {
                                for(int jj = ii + 1;jj<=12;++jj) {
                                    for(int kk = jj + 1;kk<=12;++kk) {
                                        for(int ll = kk + 1;ll<=12;++ll) {
                                            int x = (ii != i) + (jj != j) + (kk != k) + (ll != l);
                                            double tmp = min(dp[idx - 1][ii][jj][kk][ll], x == 0 ? 2e9 : (t[idx] - t[idx - 1] + 0.0) / x);
                                            dp[idx][i][j][k][l] = max(dp[idx][i][j][k][l], tmp);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        double ans = 0;
        for(int i = 1;i<=12;++i) {
            for(int j = i + 1;j<=12;++j) {
                for(int k = j + 1;k<=12;++k) {
                    for(int l = k + 1;l<=12;++l) {
                        ans = max(ans, dp[n][i][j][k][l]);
                    }
                }
            }
        }
        printf("%.2f\n", ans == 2e9 ? 0 : ans);
    }
} d4;

struct D3 {
    double dp[N][15][15][15];
    void solve() {
        for(int i = 1;i<=12;++i) {
            for(int j = i + 1;j<=12;++j) {
                for(int k = j + 1;k<=12;++k) {
                    dp[0][i][j][k] = 2e9;
                }
            }
        }
        for(int idx = 1;idx<=n;++idx) {
            scanf("%d%d", t + idx, p + idx);
            for(int i = 1;i<=12;++i) {
                for(int j = i + 1;j<=12;++j) {
                    for(int k = j + 1;k<=12;++k) {
                        if(i != p[idx] && j != p[idx] && k != p[idx]) continue;
                        for(int ii = 1;ii<=12;++ii) {
                            for(int jj = ii + 1;jj<=12;++jj) {
                                for(int kk = jj + 1;kk<=12;++kk) {
                                    int x = (ii != i) + (jj != j) + (kk != k);
                                    double tmp = min(dp[idx - 1][ii][jj][kk], x == 0 ? 2e9 : (t[idx] - t[idx - 1] + 0.0) / x);
                                    dp[idx][i][j][k] = max(dp[idx][i][j][k], tmp);
                                }
                            }
                        }
                    }
                }
            }
        }
        double ans = 0;
        for(int i = 1;i<=12;++i) {
            for(int j = i + 1;j<=12;++j) {
                for(int k = j + 1;k<=12;++k) {
                    ans = max(ans, dp[n][i][j][k]);
                }
            }
        }
        printf("%.2f\n", ans == 2e9 ? 0 : ans);
    }
} d3;

struct D2 {
    double dp[N][15][15];
    void solve() {
        for(int i = 1;i<=12;++i) {
            for(int j = i + 1;j<=12;++j) {
                dp[0][i][j] = 2e9;
            }
        }
        for(int idx = 1;idx<=n;++idx) {
            scanf("%d%d", t + idx, p + idx);
            for(int i = 1;i<=12;++i) {
                for(int j = i + 1;j<=12;++j) {
                    if(i != p[idx] && j != p[idx]) continue;
                    for(int ii = 1;ii<=12;++ii) {
                        for(int jj = ii + 1;jj<=12;++jj) {
                            int x = (ii != i) + (jj != j);
                            double tmp = min(dp[idx - 1][ii][jj], x == 0 ? 2e9 : (t[idx] - t[idx - 1] + 0.0) / x);
                            dp[idx][i][j] = max(dp[idx][i][j], tmp);
                        }
                    }
                }
            }
        }
        double ans = 0;
        for(int i = 1;i<=12;++i) {
            for(int j = i + 1;j<=12;++j) {
                ans = max(ans, dp[n][i][j]);
            }
        }
        printf("%.2f\n", ans == 2e9 ? 0 : ans);
    }
} d2;

struct D1 {
    double dp[N][15];
    void solve() {
        for(int i = 1;i<=12;++i) dp[0][i] = 2e9;
        for(int idx = 1;idx<=n;++idx) {
            scanf("%d%d", t + idx, p + idx);
            for(int i = 1;i<=12;++i) {
                if(i != p[idx]) continue;
                for(int ii = 1;ii<=12;++ii) {
                    int x = (ii != i);
                    double tmp = min(dp[idx - 1][ii], x == 0 ? 2e9 : (t[idx] - t[idx - 1] + 0.0) / x);
                    dp[idx][i] = max(dp[idx][i], tmp);
                }
            }
        }
        double ans = 0;
        for(int i = 1;i<=12;++i) {
            ans = max(ans, dp[n][i]);
        }
        printf("%.2f\n", ans == 2e9 ? 0 : ans);
    }
} d1;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &d);
    switch (d) {
        case 1: d1.solve(); break;
        case 2: d2.solve(); break;
        case 3: d3.solve(); break;
        case 4: d4.solve(); break;
    }
    return 0;
}
