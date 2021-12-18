#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], pos;

struct fenwick {
    int c[N];
    void update(int a, int b) {
        for(int i = a;i<N;i += i & (-i)) c[i] += b;
    }
    int query(int a) {
        int ans = 0;
        for(int i = a;i;i -= i & (-i)) ans += c[i];
        return ans;
    }
} fen;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    fen.update(a[n], 1);
    for(int i = n - 1;i;--i) {
        if(a[i] > a[i + 1]) {
            pos = i;
            break;
        }
        fen.update(a[i], 1);
    }
    cout<<pos<<'\n';
    for(int i = 1;i<=pos;++i) {
        cout<<pos - i + fen.query(a[i]);
        cout<<(i == pos ? '\n' : ' ');
        fen.update(a[i], 1);
    }
    return 0;
}

