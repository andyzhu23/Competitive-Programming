#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define fir first
#define sec second
using pii = pair<int, int>;
pii a[N];
int n, buy, ans;

priority_queue<int, vector<int>, greater<int> > heap;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        int u, v;
        cin>>u>>v;
        a[i] = {u, v};
    }
    sort(a + 1, a + n + 1, [&](pii& a, pii& b) {
        return a.fir == b.fir ? a.sec > b.sec : a.fir < b.fir;
    });
    for(int i = n;i;--i) {
        auto[u, v] = a[i];
        u -= buy + i - 1;
        heap.push(v);
        if(u <= 0) continue;
        while(u--) {
            ans += heap.top(); heap.pop();
            ++buy;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
