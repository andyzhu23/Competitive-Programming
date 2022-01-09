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
const int N = 1e3 + 10;
int a[N][N], hor[N][N], l[N];

template <typename T> void ckmax(T& a, T b) { a = max(a, b); }

void solve() {
    int n = read(), m = read();
    for(int i = 1;i<=n;++i) {
        for(int j = 1;j<=m;++j) {
            do {a[i][j] = getchar();} while(!isalpha(a[i][j]));
            hor[i][j] = a[i][j] == 'F' ? hor[i][j - 1] + 1 : 0;
        }
    }
    int ans = 0;
    for(int j = 1;j<=m;++j) {
        stack<int> stk;
        for(int i = 1;i<=n;++i) {
            if(hor[i][j] == 0) while(!stk.empty()) stk.pop();
            while(!stk.empty() && hor[stk.top()][j] >= hor[i][j]) stk.pop();
            if(stk.empty()) l[i] = 0;
            else l[i] = stk.top();
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i = n;i;--i) {
            if(hor[i][j] == 0) while(!stk.empty()) stk.pop(), l[i] = n;
            while(!stk.empty() && hor[stk.top()][j] >= hor[i][j]) stk.pop();
            if(stk.empty()) ckmax(ans, hor[i][j] * (n - l[i]));
            else ckmax(ans, hor[i][j] * (stk.top() - l[i] - 1));
            stk.push(i);
        }
    }
    print(ans * 3, '\n');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int k = read();
    while(k--) solve();
    return 0;
}
