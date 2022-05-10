#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int a, b;

int exgcd(int a, int b, int& x, int& y) {
    if(a * b == 0) {
        x = 1, y = 0;
        return a + b;
    }
    int gcd = exgcd(b, a % b, x, y);
    int tmp = y;
    y = x - a / b * y;
    x = tmp;
    return gcd;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>a>>b;
    int x, y;
    exgcd(a, b, x, y);
    cout<<(x + b) % b<<'\n';
    return 0;
}