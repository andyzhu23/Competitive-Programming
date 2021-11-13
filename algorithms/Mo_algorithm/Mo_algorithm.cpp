#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
        return f ? -x : x;
    }
    ll readLL() {
        ll x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
        return f ? -x : x;
    }
    void read(int& x) {x = read();}
    void read(ll& x) {x = readLL();}
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
#define all(v) v.begin(), v.end()
const int N = 3e4 + 10;
int n, m, a[N], block[N], ANS[N];

struct query {
    int l, r, id, ans;
    bool operator< (const query& other) const {
        if(block[l] == block[other.l]) return r < other.r;
        return l < other.l;
    }
};

vector<query> q;
int cnt[N];
int ans = 0;

inline void add(int p) {
    if(!cnt[a[p]]) ++ans;
    cnt[a[p]]++;
}

inline void remove(int p) {
    cnt[a[p]]--;
    if(!cnt[a[p]]) --ans;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(m);
    int bsiz = sqrt(n);
    for(int i = 1;i<=n;++i) block[i] = (i - 1) / bsiz + 1, read(a[i]);
    for(int i = 1;i<=m;++i) {
        int a = read(), b = read();
        q.push_back((query){a, b, i, 0});
    }
    sort(all(q));
    int l = 1, r = 1;
    ans = 1;
    cnt[a[1]] = 1;
    for(auto& x : q) {
        while(l != x.l || r != x.r) {
            while(l < x.l && l < r) remove(l++);
            while(l > x.l) add(--l);
            while(r < x.r) add(++r);
            while(r > x.r && l < r) remove(r--);
        }
        x.ans = ans;
        ANS[x.id] = x.ans;
    }
    for(int i = 1;i<=m;++i) print(ANS[i], '\n');
    return 0;
}
