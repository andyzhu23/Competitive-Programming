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
const int N = 1e6 + 1e5 + 5;
int n, a[N];

vector<int> mn, mx, opt[N << 1];
vector<pair<int, int> > ans;


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read();
    for(int i = 1;i<=n;++i) read(a[i]);
    int l = 0;
    for(int i = 1;i<=n;++i) {
        int id = a[i] - i + n;
        while(!mn.empty() && a[mn.back()] > a[i]) {
            opt[a[mn.back()] - mn.back() + n].pop_back();
            mn.pop_back();
        }
        while(!mx.empty() && a[mx.back()] < a[i]) mx.pop_back();
        if(!opt[id].empty()) {
            int j = opt[id].back();
            if(j > l && (mx.empty() || mx.back() < j)) ans.push_back({l = j, i});
        }
        mx.push_back(i);
        mn.push_back(i);
        opt[id].push_back(i);
    }
    print(ans.size(), '\n');
    for(auto x : ans) {
        print(x.first, ' ');
        print(x.second, '\n');
    }
    return 0;
}
