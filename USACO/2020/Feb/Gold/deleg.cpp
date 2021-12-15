#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
const int N = 1e5 + 1;
int n, dp[N], k, root;
vector<int> e[N];

int read() {
    int x = 0, f = 0;
    char c = getchar();
    while(!isdigit(c)) f |= c == '-', c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return f ? -x : x;
}

void dfs(int u = 1, int fa = 0) {
    unordered_map<int, int> opt;
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs(v, u);
        if(dp[v] == -1) {
            dp[u] = -1;
            return;
        }
        ++opt[dp[v] + 1];
    }
    vector<int> a;
    for(auto x : opt) {
        if(x.sec == 0) continue;
        int y = 0;
        if(x.fir == k || x.fir == 0) continue;
        if((k & 1) == 0 && x.fir == (k >> 1)) {
            if(x.sec & 1) y = x.fir;
        } else {
            y = abs(opt[x.fir] - opt[k - x.fir]);
            if(y > 1) {
                dp[u] = -1;
                return;
            }
            if(y) y = opt[x.fir] < opt[k - x.fir] ? k - x.fir : x.fir;
            opt[k - x.fir] = opt[x.fir] = 0;
        }
        if(y) a.pb(y);
    }
    if(a.size() > 1) dp[u] = -1;
    else if(a.empty()) dp[u] = 0;
    else dp[u] = a[0];
}

bool ok() {
    memset(dp, 0, sizeof(dp));
    dfs();
    return dp[1] == 0;
}

void dfs2(int u, int fa = 0) {
    for(int v : e[u]) {
        if(v == fa) continue;
        dfs2(v, u);
        dp[u] += dp[v] + 1;
    }
}

bool ok2() {
    unordered_map<int, int> opt;
    for(int v : e[root]) {
        ++opt[(dp[v] + 1) % k];
    }
    vector<int> a;
    for(auto x : opt) {
        if(x.sec == 0) continue;
        int y = 0;
        if(x.fir == k || x.fir == 0) continue;
        if((k & 1) == 0 && x.fir == (k >> 1)) {
            if(x.sec & 1) y = x.fir;
        } else {
            y = abs(opt[x.fir] - opt[k - x.fir]);
            if(y > 1) return 0;
            if(y) y = opt[x.fir] < opt[k - x.fir] ? k - x.fir : x.fir;
            opt[k - x.fir] = opt[x.fir] = 0;
        }
        if(y) a.pb(y);
    }
    return a.empty();
}

int in[N], cnt;
int main() {
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    n = read();
    for(int i = 1;i<n;++i) {
        int a = read(), b = read();
        e[a].pb(b);
        e[b].pb(a);
        in[a]++;
        in[b]++;
    }
    for(int i = 1;i<=n;++i) {
        if(in[i] > in[root]) root = i;
        cnt += in[i] > 2;
    }
    if(cnt == 1) {
        dfs2(root);
        for(k = 1;k<n;++k) {
            if((n - 1) % k == 0) {
                ok2() ? putchar('1') : putchar('0');
            } else putchar('0');
        }
        return 0;
    }
    for(k = 1;k<n;++k) {
        if((n - 1) % k == 0) {
            ok() ? putchar('1') : putchar('0');
        } else putchar('0');
    }
    putchar('\n');
    return 0;
}
