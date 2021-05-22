/*
 * we need to use SPFA to do this question. However, we also need to take account of
 * the height of the ship. Therefore, we need to add a dimension in our dist array dist[i][j] to store
 * the minimum dist from a to i when the ship rack is exactly j. When we are enumerating all adjacent node in
 * SPFA, we need to also enumerate through all possible height values so that we can get all the minimum roads.
 * When we get the dist array, all we have to do is to find the smallest element in dist[b]
 */


#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
const int N = 2e3 + 10;
const int INF = 1e9;
struct node{
    int v, t, h;
    node(int V, int T, int H){
        v = V, t = T, h = H;
    }
};
typedef vector<node> VII;
typedef queue<int> QII;
VII e[N];
int k, n, m, dist[N][N];
QII q;
bool inq[N];
int a, b;

void SPFA(){
    while(!q.empty()){
        int u = q.front(); q.pop();

        inq[u] = false;
        for(node nde : e[u]){
            int v = nde.v;
            int t = nde.t;
            int h = nde.h;
            for(int i = h;i<k;i++){
                if(dist[v][i] > dist[u][i - h] + t){
                    dist[v][i] = dist[u][i - h] + t;
                    if(!inq[v]){
                        q.push(v);
                    }
                    inq[v] = true;
                }
            }
        }
    }
}

int main(){
    cin>>k>>n>>m;
    for(int i = 1;i<=m;i++){
        int u, v, t, h;
        cin>>u>>v>>t>>h;
        e[u].pb(node(v, t, h));
        e[v].pb(node(u, t, h));
    }
    cin>>a>>b;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=k;j++){
            dist[i][j] = INF;
        }
    }
    dist[a][0] = 0;
    q.push(a);
    inq[a] = true;
    SPFA();
    int ans = INF;
    for(int i = 0;i<k;i++){ // make sure that i starts with 0 not 1
        ans = min(ans, dist[b][i]);
    }
    if(ans == INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
