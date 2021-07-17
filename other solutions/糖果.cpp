#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
#define mp make_pair
#define pb push_back

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
using vi = vec<int>;
using vb = vec<bool>;
using vpii = vec<pii>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vec<T>, greater<T> >;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int n, k;
ll dist[N];
int cnt[N];

struct spfa{
    vpii e[N];
    bool inq[N];
    inline void update(int x, int a, int b) {
        if(x == 1) e[a].pb(mp(b, 0)), e[b].pb(mp(a, 0));
        else if(x == 2) e[a].pb(mp(b, 1));
        else if(x == 3) e[b].pb(mp(a, 0));
        else if(x == 4) e[b].pb(mp(a, 1));
        else e[a].pb(mp(b, 0));
    }

    inline bool disjoint() {
        queue<int> q;
        bool vis[N] = {0};
        q.push(0);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = 1;
            for(pii v : e[u]) {
                if(vis[v.fir]) continue;
                vis[v.fir] = 1;
                q.push(v.fir);
            }
        }
        for(int i = 1;i<=n;i++) if(!vis[i]) return true;
        return false;
    }

    inline ll SPFA() {
        memset(dist, -63, sizeof(dist));
        dist[0] = 0;
        deque<int> q;
        q.pb(0);
        while(!q.empty()) {
            int u = q.front(); q.pop_front();
            inq[u] = 0;
            cnt[u] ++;
            if(cnt[u] > n) {
                return -1;
            }
            for(pii v : e[u]) {
                if(dist[v.fir] < dist[u] + v.sec) {
                    dist[v.fir] = dist[u] + v.sec;
                    if(inq[v.fir]) continue;
                    inq[v.fir] = 1;
                    if(q.front() > v.fir) q.push_front(v.fir);
                    q.pb(v.fir);
                }
            }
        }
        ll ans = 0;
        for(int i = 0;i<=n;i++) ans += dist[i];
        return ans;
    }

} SP;

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i = 1;i<=k;i++) {
        int x, a, b;
        cin>>x>>a>>b;
        SP.update(x, a, b);
    }
    for(int i = 1;i<=n;i++) {
        SP.e[0].pb(mp(i, 1));
    }
    if(SP.disjoint()) cout<<-1<<endl;
    else cout<<SP.SPFA()<<endl;
    return 0;
}
