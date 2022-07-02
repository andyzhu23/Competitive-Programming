#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace fast_io {
    int read() {int x = 0, f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();return f ? -x : x;}
    long long readLL() {long long x = 0, f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();return f ? -x : x;}
    void read(int& x) {x = read();}
    void read(long long& x) {x = readLL();}
    template<typename T> void print(T x) {if (x < 0) putchar('-'), x = -x;if (x >= 10) print(x / 10);putchar(x % 10 + '0');}
    template<typename T> void print(T x, char let) {print(x), putchar(let);}
}
using namespace fast_io;
const int N = 5e6 + 5;
#define chk(rt) (rc[fa[rt]] != rt)
int n, v[N], cnt[N];
ll k, val[N], sum[N];

int lc[N], rc[N], root, tot, sz[N], fa[N];

void push_up(int rt) {
    sz[rt] = sz[lc[rt]] + sz[rc[rt]] + cnt[rt];
    sum[rt] = sum[lc[rt]] + sum[rc[rt]] + cnt[rt] * val[rt];
    fa[lc[rt]] = fa[rc[rt]] = rt;
}

void turn(int x) {
    int y = fa[x];
    int z = fa[y];
    int tmp;
    if(chk(x)) {
        tmp = rc[x];
        rc[x] = y;
        lc[y] = tmp;
    } else {
        tmp = lc[x];
        lc[x] = y;
        rc[y] = tmp;
    }
    fa[tmp] = y;
    fa[y] = x;
    fa[x] = z;
    lc[z] == y ? lc[z] = x : rc[z] = x;
    push_up(y);
    push_up(x);
}

void splay(int rt) {
    while(fa[rt]) {
        if(fa[fa[rt]]) {
            if(chk(fa[rt]) == chk(rt)) turn(fa[rt]);
            else turn(rt);
        }
        turn(rt);
    }
    root = rt;
}

int insert(int& rt, ll x, int c) {
    if(rt == 0) {
        rt = ++tot;
        val[rt] = x;
        cnt[rt] = c;
        push_up(rt);
        return rt;
    }
    int tmp;
    if(val[rt] == x) tmp = rt, cnt[rt] += c, sum[rt] += c * x;
    else if(val[rt] > x) tmp = insert(lc[rt], x, c);
    else tmp = insert(rc[rt], x, c);
    push_up(rt);
    return tmp;
}

void insert(ll x, int c) {
    int rt = insert(root, x, c);
    splay(rt);
}

int lft;

int id(int rt, int x) {
    if(sz[lc[rt]] >= x) return id(lc[rt], x);
    else if(sz[lc[rt]] + cnt[rt] < x) return id(rc[rt], x - sz[lc[rt]] - cnt[rt]);
    else {
        lft = x - sz[lc[rt]];
        return rt;
    }
}

int mov = 0;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n), read(k);
    for(int i = 1;i<=n;++i) {
        ll j = i + mov;
        read(v[i]);
        if(v[i] == 1) {
            root = 0;
            print(k, '\n');
            insert(k - j, 1);
            if(i > 1) insert(-j, i - 1);
        } else {
            int x = id(root, v[i] - 1);
            splay(x);
            int tmp = rc[x];
            rc[x] = 0;
            int tmp2 = cnt[x];
            cnt[x] = lft;
            push_up(x);
            if(k - (sum[x] + j * sz[x]) >= 0) {
                print(k - (sum[x] + j * sz[x]), '\n');
                int tmp = sz[x];
                ll tmp2 = sum[x];
                insert(-j, i - 1 - tmp);
                insert(k - (tmp2 + j * tmp) - j, 1);
            } else {
                print(-1, '\n');
                rc[x] = tmp;
                cnt[x] = tmp2;
                push_up(x);
                insert(-j, 1);
                --mov;
            }
        }
    }
    return 0;
}

