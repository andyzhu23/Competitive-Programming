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

const int N = 1e5 + 10;

int n, a[N];

struct Trie {
    struct node {
        int val;
        int to[2];
    } tr[30 * N];
    int tot = 1;

    void update(int x) {
        int rt = 1;
        for(int i = 31;i>=0;--i) {
            int& nxt = tr[rt].to[(x & (1 << i)) != 0];
            if(!nxt) nxt = ++tot;
            rt = nxt;
        }
    }
    int query(int x) {
        int rt = 1, ans = 0;
        for(int i = 31;i>=0;--i) {
            int nxt1 = tr[rt].to[((x & (1 << i)) != 0) ^ 1];
            int nxt2 = tr[rt].to[((x & (1 << i)) != 0)];
            if(nxt1) rt = nxt1, ans |= 1 << i;
            else rt = nxt2;
        }
        return ans;
    }
} trie;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<=n;++i) {
        read(a[i]);
        trie.update(a[i]);
    }
    int ans = 0;
    for(int i = 1;i<=n;++i) {
        ans = max(ans, trie.query(a[i]));
    }
    print(ans, '\n');
    return 0;
}
