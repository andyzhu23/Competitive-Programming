#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int n;

struct node {
    double x, y;
} a[N];
int o;

bool cross(node o, node a, node b) {
    return (a.y - o.y) * (b.x - o.x) <= (b.y - o.y) * (a.x - o.x);
}

bool cross2(node o, node a, node b) {
    return (a.y - o.y) * (b.x - o.x) == (b.y - o.y) * (a.x - o.x);
}

double len(node a, node b) {
    return sqrt((b.y - a.y) * (b.y - a.y) + (b.x - a.x) * (b.x - a.x));
}

vector<int> stk;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    o = 1;
    for(int i = 1;i<=n;++i) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        a[i] = {x, y};
        if(y == a[o].y && x < a[o].x) o = i;
        if(y < a[o].y) o = i;
    }
    swap(a[1], a[o]);
    sort(a + 2, a + n + 1, [&](node& u, node& v) {
        if(cross2(a[1], u, v)) return u.x < v.x;
        return cross(a[1], u, v);
    });
    double ans = 0;
    for(int i = 1, j;i<=n;++i) {
        while(stk.size() >= 2 && !cross(a[stk[stk.size() - 2]], a[stk.back()], a[i])) stk.pop_back();
        stk.push_back(i);
    }
    for(int i = 1;i<=stk.size();++i) ans += len(a[stk[i % stk.size()]], a[stk[i - 1]]);
    printf("%.2f", ans);
    return 0;
}
