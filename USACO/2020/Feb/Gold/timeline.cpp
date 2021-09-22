#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
using ll = long long;
using pii = pair<int, int>;
using vpii = vector<pii>;
using pll = pair<ll, ll>;
const int N = 1e5 + 10;
int n, m, c, s[N];
bool inq[N];
ll d[N];
vpii e[N];

queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    cin>>n>>m>>c;
    memset(d, -0x3f, sizeof(d));
    for(int i = 1;i<=n;++i) {
        cin>>s[i];
        e[0].pb(mp(i, s[i]));
        e[i].pb(mp(0, -m));
    }
    for(int i = 1;i<=c;++i) {
        int a, b, x;
        cin>>a>>b>>x;
        e[a].pb(mp(b, x));
    }
    d[0] = 0;
    q.push(0);
    inq[0] = 1;
    // SPFA
    while(!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for(pii v : e[u]) {
            if(d[v.fir] < d[u] + v.sec) {
                d[v.fir] = d[u] + v.sec;
                if(inq[v.fir]) continue;
                inq[v.fir] = 1;
                q.push(v.fir);
            }
        }
    }

    for(int i = 1;i<=n;++i) cout<<d[i]<<'\n';
    return 0;
}
