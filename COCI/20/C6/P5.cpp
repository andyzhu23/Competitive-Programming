#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

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
#define pb push_back
const int N = 2e5 + 10;
struct query {int l, r, id;};
vector<query> q;
int n, Q, a[N], block[N], ans[N];

struct fenwick {
    int c[N];
    void update(int a, int b) {
        for(int i = a;i<N;i += i & (-i)) c[i] += b;
    }
    int query(int a) {
        int ans = 0;
        for(int i = a;i;i -= i & (-i)) ans += c[i];
        return ans;
    }
    int query(int a, int b) {return query(b) - query(a - 1);}
} fen;

void add(int x) {fen.update(a[x], 1);}
void remove(int x) {fen.update(a[x], -1);}

int bs() {
    int l = 1, r = 2e5, ans = 1;
    while(l <= r) {
        int mid = l + r >> 1;
        if(fen.query(mid, N - 1) >= mid) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), Q = read();
    int bsiz = sqrt(n);
    for(int i = 1;i<=n;++i) a[i] = read(), block[i] = (i - 1) / bsiz + 1;
    for(int i = 1;i<=Q;++i) {
        int l = read(), r = read();
        q.pb({l, r, i});
    }
    sort(q.begin(), q.end(), [&](query& a, query& b) {
        if(block[a.l] == block[b.l]) 
            return block[a.l] & 1 ? a.r < b.r : a.r > b.r;
        return a.l < b.l;
    });
    int l = 1, r = 1;
    add(1);
    for(auto x : q) {
        while(x.l < l) add(--l);
        while(x.r > r) add(++r);
        while(x.l > l) remove(l++);
        while(x.r < r) remove(r--);
        ans[x.id] = bs();
    }
    for(int i = 1;i<=Q;++i) print(ans[i], '\n');
    return 0;
}
