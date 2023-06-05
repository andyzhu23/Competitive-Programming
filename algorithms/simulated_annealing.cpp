#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e4 + 5;
int n, x[N], y[N], w[N];

double Rand() { return (double)rand() / RAND_MAX; }

struct node {
    double x, y, ret;
    bool operator<(const node& other) const {
        return ret < other.ret;
    }
} ans;

double calc(double xx, double yy) {
    double ret = 0;
    for(int i = 1;i<=n;++i) {
        double dx = x[i] - xx, dy = y[i] - yy;
        ret += sqrt(dx * dx + dy * dy) * w[i];
    }
    if(ret < ans.ret) ans = {xx, yy, ret};
    return ret;
}

void simulateAnneal() {
    double t = 100000;
    double xx = ans.x, yy = ans.y;
    while(t > 0.001) {
        double nxtx = xx + t * (Rand() * 2 - 1);
        double nxty = yy + t * (Rand() * 2 - 1);
        double d = calc(nxtx, nxty) - calc(xx, yy);
        if(exp(-d / t) > Rand()) xx = nxtx, yy = nxty;
        t *=0.97;
    }
    for(int i = 1;i<=10000;++i) {
        double nxtx = ans.x + t * (Rand() * 2 - 1);
        double nxty = ans.y + t * (Rand() * 2 - 1);
        calc(nxtx, nxty);
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    ans.ret = inf;
    for(int i = 1;i<=n;++i) {
        cin>>x[i]>>y[i]>>w[i];
        ans.x += x[i];
        ans.y += y[i];
    }
    ans.x /= n;
    ans.y /= n;
    ans.ret = calc(ans.x, ans.y);
    simulateAnneal();
    printf("%.3f %.3f\n", ans.x, ans.y);
    return 0;
}
