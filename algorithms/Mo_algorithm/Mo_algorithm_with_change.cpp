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
#define all(v) v.begin(), v.end()
const int N = 1e4 + 10;
int n, m, a[N], block[N], bsiz;

struct query {
    int t, l, r, id, ans;
    bool operator<(const query& other) const {
        if(block[l] == block[other.l]) {
            if(block[r] == block[other.r]) return t < other.t;
            else return block[r] < block[other.r];
        } else return block[l] < block[other.l];
    }
};

struct change {
    int t, u, x;
};

vector<query> q;
vector<change> ch(1);

int ans = 0, cnt[int(1e6 + 10)];

void add(int c) {ans += ++cnt[c] == 1;}
void remove(int c) {ans -= --cnt[c] == 0;}
void update(int x, int y, int t) {
    if(ch[t].u >= x && ch[t].u <= y) {
        add(ch[t].x);
        remove(a[ch[t].u]);
    }
    swap(ch[t].x, a[ch[t].u]);
}

bool cmp(query& a, query& b) {
    return a.id < b.id;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read(), m = read();
    bsiz = sqrt(n);
    for(int i = 1;i<=n;++i) read(a[i]), block[i] = (i - 1) / bsiz + 1;
    int rs = 0;
    for(int i = 1;i<=m;++i) {
        char opt; cin>>opt;
        int l = read(), r = read();
        if(opt == 'Q') q.pb({rs, l, r, i, 0});
        else ch.pb({++rs, l, r});
    }
    sort(all(q));
    int l = 1, r = 1, t = 0;
    ++ans, ++cnt[a[1]];
    for(auto& x : q) {
        while(l > x.l) add(a[--l]);
        while(r < x.r) add(a[++r]);
        while(l < x.l) remove(a[l++]);
        while(r > x.r) remove(a[r--]);
        while(t > x.t) update(l, r, t--);
        while(t < x.t) update(l, r, ++t);
        x.ans = ans;
    }
    sort(all(q), cmp);
    for(auto& x : q) print(x.ans, '\n');
    return 0;
}
