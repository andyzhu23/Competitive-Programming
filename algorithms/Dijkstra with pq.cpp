#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define f first
#define s second
#define p pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
const int N = 5e4 + 10;
const int INF = 2e9 + 10;
int dist[N], vis[N];
vector<p> e[N];
int n, m;

struct cmp{
    bool operator() (const p &a, const p &b) {
        return a.s > b.s;
    }
};

priority_queue<p, vector<p>, cmp> pq;



void dij(int start){
    //initialize
    for(int i = 1;i<=n;i++) dist[i] = INF;
    dist[start] = 0;
    pq.push(mp(start, 0));
    while(!pq.empty()){
        // get smallest
        p v = pq.top(); pq.pop();
        if(vis[v.f]) continue;
        vis[v.f] = true;
        // update adjacent
        for(p i:e[v.f]){
            if(i.s + v.s < dist[i.f]) {
                dist[i.f] = i.s + v.s;
                pq.push(mp(i.f, i.s + v.s));
            }

        }
    }
}


int main() {
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        e[a].pb(make_pair(b,c));
    }
    dij(1);
    cout<<dist[n]<<endl;
    return 0;
}
