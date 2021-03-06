#include <iostream>
#include <vector>
#include <queue>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef queue<int> QII;
const int N = 1e4 + 10;
const int INF = 1e9;
VII e[N];
QII q;
int n, m, dist[N],inq[N];
void SPFA(int start){
    for(int i = 1;i<=n;i++) dist[i] = INF;
    dist[start] = 0;
    q.push(start);
    inq[start] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        inq[u] = false;
        for(PII next: e[u]){
            int v = next.f;
            int w = next.s;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if(!inq[v]){
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        e[a].pb(mp(b,c));
        e[b].pb(mp(a,c));
    }
    SPFA(1);
    cout<<dist[n]<<endl;
    return 0;
}
