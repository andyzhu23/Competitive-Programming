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

const int N = 1e5 + 5;
int n, Q, bsiz, block[N], a[N], mx = 0, ans[N], start[N], rmx = 0, cnt3[N], cnt2[N];
bool vis[N];
struct query {
    int l, r, id;
    inline bool operator<(const query& other) const {
        return r < other.r;
    }
};
vector<query> q[350];
int v[N], vp;


inline void addr(int x) {
    ++cnt3[a[x]];
    if(cnt2[a[x]] + cnt3[a[x]] == cnt2[mx] + cnt3[mx]) mx = max(a[x], mx);
    else if(cnt2[a[x]] + cnt3[a[x]] > cnt2[mx] + cnt3[mx]) mx = a[x];
    if(cnt3[a[x]] == cnt3[rmx]) rmx = max(a[x], rmx);
    else if(cnt3[a[x]] > cnt3[rmx]) rmx = a[x];
}

inline void addl(int x) {
    ++cnt2[a[x]];
    if(cnt2[a[x]] + cnt3[a[x]] == cnt2[mx] + cnt3[mx]) mx = max(a[x], mx);
    else if(cnt2[a[x]] + cnt3[a[x]] > cnt2[mx] + cnt3[mx]) mx = a[x];
    if(!vis[a[x]]) v[++vp] = a[x];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(Q);
    bsiz = sqrt(n);
    for(int i = 1;i<=n;++i) a[i] = read(), block[i] = (i - 1) / bsiz + 1;
    for(int i = 1;i<=Q;++i) {
        int l = read(), r = read();
        start[block[l]] = max(start[block[l]], l);
        q[block[l]].push_back({l, r, i});
    }
    for(int i = 1;i<=block[n];++i) if(!q[i].empty()) {
        sort(q[i].begin(), q[i].end());
        query& x = *(q[i].begin());
        int l = start[i];
        int r = x.r - 1;
        mx = 0;
        if(l > r) for(int i = r + 1;i<l;++i) cnt3[a[i]]--;
        if(l <= r) for(int i = l;i<=r;++i) addr(i);
        for(query& x : q[i]) {
            while(r < x.r) addr(++r);
            if(l >= x.l) while(l > x.l) addl(--l);
            else {
                mx = rmx;
                for(int i = 1;i<=vp;++i) {
                    cnt2[v[i]] = 0;
                    vis[v[i]] = 0;
                }
                vp = 0;
                l = start[i];
                while(l > x.l) addl(--l);
            }
            ans[x.id] = mx;
        }
        for(int j = start[i];j<=r;++j) cnt3[a[j]]--;
        for(int i = 1;i<=vp;++i) {
            cnt2[v[i]] = 0;
            vis[v[i]] = 0;
        }
        vp = 0;
    }
    for(int i = 1;i<=Q;++i) print(ans[i], '\n');
    return 0;
}
