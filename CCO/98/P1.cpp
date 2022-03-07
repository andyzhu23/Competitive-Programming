#include <bits/stdc++.h>
using namespace std;

struct big {
    int n[105];
    big operator+(const big& other) const {
        big ans;
        memset(ans.n, 0, sizeof(ans.n));
        int carry = 0;
        for(int i = 1;i<=100;++i) {
            ans.n[i] = n[i] + other.n[i] + carry;
            carry = ans.n[i] / 10;
            ans.n[i] %= 10;
        }
        return ans;
    }
    void print() {
        int i;
        for(i = 100;i;--i) {
            if(n[i]) break;
        }
        string ans;
        for(int j = i;j;--j) {
            ans += ('0' + n[j]);
        }
        cout<<ans<<'\n';
    }
} f[205];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    f[1].n[1] = f[2].n[1] = 1;
    for(int i = 3;i<=205;++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    int n; cin>>n;
    while(1) {
        f[n].print();
        cin>>n;
        if(n == 0) break;
    }

    return 0;
}
