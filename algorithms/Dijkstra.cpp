#include <iostream>
#include <vector>
#define f first
#define s second
#define p pair<int, int>
using namespace std;
const int N = 1e3 + 10;
const int INF = 2e9 + 10;
vector<p> e[N];
int dist[N];
int vis[N];
int n, m;

/*  1. init
 *  2. for loos n times
 *      2.1 find the point of minimum dist[i], no visit
 *      2.2 update adjacent point
 *
 */

void dij(int start){
    // step 1
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[start] = 0;
    //  step 2
    for(int i = 1; i <= n; i++) {
        //  step 2.1
        int v = -1;         //  minimum dist point
        for(int j = 1; j <= n; j++) {       //  enumerate
            //  condition 1: vis = 0, 2: minimum
            if(vis[j] == 0 && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        if(v == -1) break;
        vis[v] = 1;
        //  step 2.2
        for(int j = 0; j < e[v].size(); j++) {  //  enumerate adjacent point
            int u = e[v][j].f, w = e[v][j].s;
            dist[u] = min(dist[u], dist[v] + w);    //  update distance
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        e[a].push_back(make_pair(b, c));
        e[b].push_back(make_pair(a, c));
    }
    dij(1);
    cout<<dist[n]<<endl;

    return 0;
}
