/*
 * Author: Andy Zhu
 * @date    2022-03-13 11:20:06
 * @version 1.0.0
 */

#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

const int N = 1e5 + 5;
int f[N], n, m, a[N];
ordered_set<int> bst[N];
int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
void merge(int u, int v) {
    int fu = Find(u);
    int fv = Find(v);
    if(bst[fu].size() < bst[fv].size()) swap(fu, fv);
    f[fv] = fu;
    while(!bst[fv].empty()) {
        bst[fu].insert(*bst[fv].begin());
        bst[fv].erase(bst[fv].begin());
    }
}

int rnk[N];

int main(){
    read(n), read(m);
    iota(f, f + n + 1, 0);
    for(int i = 1;i<=n;++i) {
      a[i] = read();
      bst[i].insert(a[i]);
      rnk[a[i]] = i;
    }
    for(int i = 1;i<=m;++i) {
        int u = read(), v = read();
        merge(u, v);
    }
    int q = read();
    while(q--) {
        char c;
        do{c = getchar();} while(!isalpha(c));
        int u = read(), v = read();
        if(c == 'Q') {
            if(bst[Find(u)].size() < v) print(-1, '\n');
            else print(rnk[*(bst[Find(u)].find_by_order(v - 1))], '\n');
        } else merge(u, v);
    }
}
