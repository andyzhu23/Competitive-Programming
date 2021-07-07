#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define sec second

template<typename T> using vec = vector<T>;
using vi = vec<int>;
using vb = vec<bool>;
using pii = pair<int, int>;
using ll = long long;

const int N = 1e3 + 10;
const ll INF = 0x7f7f7f7f;
int n, ml, md, m;

vi Map[N];

struct edge{
    int u, v, w;
    edge(int U, int V, int W) {
        u = U, v = V, w = W;
    }
};

struct spfa {
    ll dist[N];
    int f[N];
    vec<edge> e;

    bool unreach() {
        queue <int> q;
        q.push(1);
        bool vis[N] = {0};
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if(vis[cur]) continue;
            vis[cur] = 1;
            if(cur == n) return false;
            for(int v : Map[cur]) {
                q.push(v);
            }
        }
        return true;
    }

    // Actually changed to Bellman-Ford but too lazy to change the name
    bool SPFA() {
        bool update;
        memset(dist, 127, sizeof(dist));
        dist[1] = 0;
        for(int i = 1;i<=n + 10;i++) {
            update = 0;
            for(int i = 0;i<m;i++) {
                int u = e[i].u;
                int v = e[i].v;
                int w = e[i].w;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    update = 1;
                }
            }
            if(!update) break;
        }
        if(update) return true;
        return false;
    }

};

spfa SP;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>ml>>md;
    while(ml--) {
        int u, v, w;
        cin>>u>>v>>w;
        SP.e.pb(edge(u, v, w));
        Map[u].pb(v);
    }
    while(md--) {
        int u, v, w;
        cin>>u>>v>>w;
        SP.e.pb(edge(v, u, -w));
        Map[v].pb(u);
    }
    for(int i = 2;i<=n;i++) {
        SP.e.pb(edge(i, i - 1, 0));
        Map[i].pb(i - 1);
    }
    m = SP.e.size();

    if(SP.unreach()) {
        cout<<-2<<"\n";
        return 0;
    }

    if(SP.SPFA()) {
        cout<<-1<<"\n";
        return 0;
    }
    else cout<<SP.dist[n]<<"\n";
    return 0;
}
