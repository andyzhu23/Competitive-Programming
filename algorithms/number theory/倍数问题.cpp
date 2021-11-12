#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string a;
int b;
const int N = 1e7 + 10;
struct bigInt {
    int num[N], len = 0;
    void build(string& s) {
        len = s.size();
        for(int i = 1;i<=s.size();++i) {
            num[i] = s[i - 1] - '0';
        }
    }
    ll operator%(const int& a) const {
        ll ans = 0;
        for(int i = 1;i<=len;++i) {
            ans = ans * 10 % a + num[i];
            ans %= a;
        }
        return ans;
    }
} n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    cin>>b;
    n.build(a);
    cout<<(n % b == 0 ? "YES" : "NO")<<'\n';
    return 0;
}
