/*
 * Author: Andy Zhu
 * @date    2022-03-04 11:04:54
 * @version 1.0.0
 */

#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;
#define ins insert
#define pb push_back
#define all(v) v.begin(), v.end()

namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    void read(int& x) {x = read();}
    template<typename T> void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
            putchar(x % 10 + '0');
    }
    template<typename T> void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;
const int N = 4e5 + 5;
int n, m, len = 0;
struct rectangle {int a, b, c, d;};
rectangle rec[N];
struct dots {
    int x, y;
    inline bool operator<(const dots& other) const {
        return x < other.x;
    }
};
dots dot[N];
set<int> disx, disy;
unordered_map<int, int> mpx, mpy;

struct seg {
    int x, l, r, val;
    inline bool operator<(const seg& other) const {
        return x < other.x;
    }
};

seg s[N];

struct fenwick {
    int c[N], d[N];
    inline int lowbit(int x) {return x & (-x);}
    inline void update(int a, int b) {
        for(int i = a;i<=len;i+=lowbit(i)) {
            c[i] += b;
            d[i] += (a - 1) * b;
        }
    }
    inline void update(int a, int b, int c) {
        update(a, c), update(b + 1, -c);
    }
    inline int query(int a) {
        int ans = 0;
        for(int i = a;i;i-=lowbit(i)) {
            ans += a * c[i] - d[i];
        }
        return ans;
    }
    inline int query(int a, int b) {
        return query(b) - query(a - 1);
    }
} fen;

int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(m);
    for(int i = 1;i<=n;++i) {
        int a = read(), b = read(), c = read(), d = read();
        rec[i] = {a, b, c, d};
        disx.ins(a);
        disx.ins(c);
        disy.ins(b);
        disy.ins(d);
    }
    for(int i = 1;i<=m;++i) {
        int x = read(), y = read();
        dot[i] = {x, y};
        disx.ins(x);
        disy.ins(y);
    }
    for(auto& x : disx) mpx[x] = ++len;
    len = 0;
    for(auto& y : disy) mpy[y] = ++len;
    for(int i = 1;i<=n;++i) {
        auto& x = rec[i];
        x.a = mpx[x.a];
        x.b = mpy[x.b];
        x.c = mpx[x.c];
        x.d = mpy[x.d];
    }
    for(int i = 1;i<=m;++i) {
        auto& x = dot[i];
        x.x = mpx[x.x];
        x.y = mpy[x.y];
    }
    int tot = 0;
    for(int i = 1;i<=n;++i) {
        auto&[a, b, c, d] = rec[i];
        s[++tot] = {a, min(b, d), max(b, d), 1};
        s[++tot] = {c + 1, min(b, d), max(b, d), -1};
    }
    sort(dot + 1, dot + m + 1);
    sort(s + 1, s + tot + 1);
    int ans = 0;
    int cnt = 1;
    for(int i = 1;i<=m;++i) {
        auto&[x, y] = dot[i];
        while(s[cnt].x <= x && cnt <= n * 2) {
            auto& y = s[cnt];
            fen.update(y.l, y.r, y.val);
            ++cnt;
        }
        ans += fen.query(y, y) != 0;
    }
    print(ans, '\n');
    return 0;
}
