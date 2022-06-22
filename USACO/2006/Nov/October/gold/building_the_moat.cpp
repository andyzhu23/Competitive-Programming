#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fir first
#define sec second
const int N = 5005;
int n;
pii a[N];
vector<int> stk;

bool cross(pii& x, pii& y, pii& z) {
    return (y.sec - x.sec) * (z.fir - x.fir) < (z.sec - x.sec) * (y.fir - x.fir);
}

double dist(pii& a, pii& b) {
    return sqrt((b.fir - a.fir) * (b.fir - a.fir) + (b.sec - a.sec) * (b.sec - a.sec));
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    int mn = 1;
    for(int i = 1;i<=n;++i) {
        scanf("%lld%lld", &a[i].fir, &a[i].sec);
        if(a[i].sec == a[mn].sec && a[i].fir < a[mn].fir) mn = i; 
        if(a[i].sec < a[mn].sec) mn = i;
    }
    swap(a[1], a[mn]);
    sort(a + 2, a + n + 1, [&](pii& u, pii& v) {
        return cross(a[1], u, v);
    });
    double ans = 0;
    for(int i = 1;i<=n;++i) {
        while(stk.size() >= 2 && !cross(a[stk[stk.size() - 2]], a[stk.back()], a[i])) stk.pop_back();
        stk.push_back(i);
    }
    stk.push_back(stk[0]);
    for(int i = 1;i<stk.size();++i) ans += dist(a[stk[i]], a[stk[i - 1]]);
    printf("%.2f\n", ans);
    return 0;
}
