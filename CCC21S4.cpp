/*
 * there is no reason to first walk and then get to the train. Therefore, we should run dij to get the minimum
 * length from n to each point, in opposite way and then enumerate choices when swapping lines
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
#define vi vector<int>

using namespace std;
const int N = 2e5 + 10;
const int INF = 2e9 + 10;
vi e[N];
int n, w, d;
int a[N];
int dist[N], vis[N], res[N];
queue<int> q;
struct p{
    int f, s, pos; // f is the shortest path from 1 to n leaving train at s position is the number of station
    p(int F, int S, int POS){
        f= F;
        s = S;
        pos = POS;
    }

};
struct cmp {
    bool operator()(const p &b, const p &c) {
        return b.f > c.f;
    }
};
priority_queue<p, vector<p>, cmp> pq;

void dij(int start){
    for(int i = 1;i<=n;i++) dist[i] = INF;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int v = q.front(); q.pop();
        if(vis[v]) continue;
        vis[v] = true;
        for(int u: e[v]){
            if(dist[u] > dist[v] + 1){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    scanf("%d %d %d",&n,&w,&d);

    for(int i =1;i<=w;i++){
        int c, b;
        scanf("%d %d",&c,&b);
        e[b].pb(c);
    }

    for(int i =1;i<=n;i++){
        scanf("%d", &a[i]);
    }

    // get the minimum value required solely by walking
    dij(n);
    for(int i = 1;i<=n;i++){
        res[i] = dist[a[i]] + i - 1;

        pq.push(p(res[i], i, a[i]));
    }

    for(int i = 1;i<=d;i++){
        int ans = INF;
        int x, y, tmp;
        scanf("%d %d",&x,&y);
        tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
        // push in the swapped solutions
        pq.push(p(dist[a[x]] + x - 1, x, a[x]));
        pq.push(p(dist[a[y]] + y - 1, y, a[y]));

        while(!pq.empty()){
            // gives us the answer
            p cur = pq.top(); pq.pop();
            // if route is swapped then we don't use it
            if(a[cur.s] != cur.pos) continue;
            ans = cur.f;
            pq.push(cur);
            break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
