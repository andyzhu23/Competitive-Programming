#include <iostream>
using namespace std;
const int N = 1e4 + 10;
const int INF= 1e9 + 10;
int n, m;
struct path{
    int from, to, cost;
}e[N];
int dist[N];
int main(){
    for(int i = 1;i<N;i++) dist[i] = INF;
    dist[1] = 0;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        e[i].from = a;
        e[i].to = b;
        e[i].cost = c;
    }

    for(int i = 1;i<=n;i++){
        bool update = false;
        for(path x: e){
            int u = x.from;
            int v = x.to;
            int w = x.cost;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                update = true;
            }
            if(dist[u] > dist[v] + w){
                dist[u] = dist[v] + w;
                update = true;
            }
        }
        if(!update){
            cout<<dist[n]<<endl;
            return 0;
        }
    }
    cout<<dist[n]<<endl;
    return 0;
}
