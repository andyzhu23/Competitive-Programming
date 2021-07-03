#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fir first
#define sec second
#define pb push_back
using ll = long long;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vi = vector<int>;


const int N = 3e4 + 10;
vpii e[N];
bool inq[N];

int n, h, dist[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>h;
    ++n;
    for(int i = 1;i<=n;i++) {
        e[i].pb(mp(i - 1, -1));
        e[i - 1].pb(mp(i, 0));
    }
    for(int i = 1;i<=h;i++) {
        int a, b, c;
        cin>>a>>b>>c;
        e[a].pb(mp(b + 1, c));
    }
    queue<int> q;
    q.push(0);
    memset(dist, -63, sizeof(dist));
    dist[0] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for(pii v : e[u]) {
            if(dist[v.fir] < dist[u] + v.sec) {
                dist[v.fir] = dist[u] + v.sec;
                if (inq[v.fir]) continue;
                inq[v.fir] = 1;
                q.push(v.fir);
            }
        }
    }
    cout<<dist[n]<<endl;
    return 0;
}
