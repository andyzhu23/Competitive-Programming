#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
const int N = 210;
int n;

struct cow {
    int x, y;
    bool operator<(const cow& other) const {
        return x < other.x;
    }
} cows[N];

vector<int> opt;

int ans, num;

void solve(int a, int b) {
    if(abs(cows[a].x - cows[b].x) < abs(cows[a].y - cows[b].y)) return;
    sort(all(opt));
    int siz = abs(cows[a].x - cows[b].x);
    int up = lower_bound(all(opt), cows[a].y) - opt.begin();
    int down = lower_bound(all(opt), cows[b].y) - opt.begin();
    if(cows[a].y < cows[b].y) swap(up, down);
    int mn = 0, mx = opt.size() - 1;
    while(opt[up] - opt[mn] > siz) ++mn;
    while(opt[mx] - opt[down] > siz) --mx;
    // two pointer here
    int top = up; // record max up
    int ok = up; // record first one ok
    int bottom = mn; // record bottom
    while(bottom <= down) {
        while(top < opt.size() && opt[top] - opt[bottom] <= siz) {
            num += opt[top] - opt[bottom] == siz;
            top++;
        }
        top--;
        if(bottom) {
            while(ok < opt.size() - 1 && opt[ok + 1] - opt[bottom - 1] - 1 <= siz) ok++;
        }
        ans += top - ok + 1;
        ++bottom;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    ans = n + 1;
    for(int i = 1;i<=n;++i) {
        int x, y;
        cin>>x>>y;
        cows[i] = {x, y};
    }
    sort(cows + 1, cows + n + 1);
    for(int i = 1;i<=n;++i) {
        opt.clear();
        opt.pb(cows[i].y);
        for(int j = i + 1;j<=n;++j) {
            opt.pb(cows[j].y);
            solve(i, j);
        }
    }
    for(int i = 1;i<=n;++i) swap(cows[i].x, cows[i].y);
    sort(cows + 1, cows + n + 1);
    for(int i = 1;i<=n;++i) {
        opt.clear();
        opt.pb(cows[i].y);
        for(int j = i + 1;j<=n;++j) {
            opt.pb(cows[j].y);
            solve(i, j);
        }
    }
    cout<<ans - num / 2<<'\n';
    return 0;
}
