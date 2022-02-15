#include <bits/stdc++.h>
using namespace std;
const int L = 15;
const int N = 1e5 + 5;

int mx, cnt;

struct num {
    int a[L], n;
    num(int x) {
        n = x;
        int len = 0;
        memset(a, 0, sizeof(a));
        while(x) {
            a[++len] = x % 10;
            x /= 10;
        }
        mx = max(len, mx);
    }
    bool operator<(const num& o) const {
        int i = cnt;
        while(a[i] == o.a[i] && i > 1) {
            --i;
        }
        return a[i] < o.a[i];
    }
};
vector<num> a;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n; cin>>n;
    for(int i = 1;i<=n;++i) {
        int x; cin>>x;
        a.push_back(num(x));
    }
    cnt = 2;
    for(cnt = 1;cnt<=mx;++cnt) {
        sort(a.begin(), a.end());
        for(int i = 1;i<=n;++i) {
            cout<<a[i - 1].n<<(i == n ? '\n' : ' ');
        }
    }
    return 0;
}