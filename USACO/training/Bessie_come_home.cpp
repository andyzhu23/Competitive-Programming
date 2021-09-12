#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
using pci = pair<char, int>;
int n;
const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;
vector<char> cow;
vector<pci> e[N];
int dist[N];
struct d {
    char id;
    bool operator<(const d& other) const {
        return dist[id] > dist[other.id];
    }
    d(char ID) {id = ID;}
};
priority_queue<d> pq;
bool vis[N];

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    memset(dist, 0x3f, sizeof(dist));
    cin>>n;
    for(int i = 1;i<=n;i++) {
        char u, v;
        int w;
        cin>>u>>v>>w;
        if(u < 'a' && u != 'Z') cow.pb(u);
        if(v < 'a' && v != 'Z') cow.pb(v);
        e[v].pb(mp(u, w));
        e[u].pb(mp(v, w));
    }
    d start = d('Z');
    dist['Z'] = 0;
    pq.push(start);
    while(!pq.empty()) {
        char u = pq.top().id; 
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(pci v : e[u]) {
            if(dist[v.fir] > dist[u] + v.sec) {
                dist[v.fir] = dist[u] + v.sec;
                d nxt = d(v.fir);
                pq.push(nxt);
            }
        }
    }
    char ans1;
    int ans2 = INF;
    for(char i : cow) {
        if(dist[i] < ans2) {
            ans2 = dist[i];
            ans1 = i;
        }
    }
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}