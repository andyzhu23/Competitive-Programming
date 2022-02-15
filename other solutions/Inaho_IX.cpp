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
using ll = long long;
const int N = 15;
const int mod = 1e9 + 7;
int n;

struct mat {
    ll a[N][N];
    mat operator*(const mat& o) {
        mat ans;
        for(int i = 1;i<=n;++i) {
            for(int j = 1;j<=n;++j) {
                ans.a[i][j] = 0;
                for(int k = 1;k<=n;++k) {
                    ans.a[i][j] = (ans.a[i][j] + a[i][k] * o.a[k][j]) % mod;
                }
            }
        }
        return ans;
    }
} a, ans, init;

string s;

template <typename T1, typename T2>
T1 fp(T1 a, T2 b) {
    if(b == 1) return a;
    T1 tmp = fp(a, b >> 1);
    if(b & 1) return tmp * tmp * a;
    else return tmp * tmp;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) s += c, c = getchar();
    for(int i = s.size() - 1;i>=0;--i) {
        if(s[i] > '0') {
            s[i]--;
            break;
        }
        s[i] = '9';
    }
    for(int i = 1;i<=n;++i) {
        a.a[1][i] = read();
        a.a[i][i - 1] = 1;
        init.a[i][1] = 1;
    }
    ans = init;
    for(int i = s.size() - 1;i>=0;--i) {
        int c = s[i] - '0';
        for(int i = 0;i<c;++i) ans = a * ans;
        a = fp(a, 10);
    }
    print(ans.a[n][1], '\n');
    return 0;
}
