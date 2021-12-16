/*
 * Author: Andy Zhu
 * @date    2021-12-16 12:52:53
 * @version 1.0.0
 */

// optimize
#pragma GCC optimize(2)

//include
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
    long long readLL() {
        long long x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    void read(int& x) {x = read();}
    void read(long long& x) {x = readLL();}
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
using pii = pair<int, int>;
ordered_set<pii> bst;
int tot = 0;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n = read();
    while(n--) {
        int opt = read();
        switch(opt) {
            case 1: bst.insert({read(), ++tot}); break;
            case 2: bst.erase(bst.upper_bound({read(), 0})); break;
            case 3: print(bst.order_of_key({read(), 0}) + 1, '\n'); break;
            case 4: print((*bst.find_by_order(read() - 1)).first, '\n'); break;
            case 5: print((*(prev(bst.lower_bound({read(), 0})))).first, '\n');; break;
            case 6: print((*bst.upper_bound({read(), tot + 1})).first, '\n'); break;
        }
    }

    return 0;
}
