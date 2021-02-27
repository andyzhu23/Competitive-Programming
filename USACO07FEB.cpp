/*
 * store graph two times, right and reversed, then use it to calculate x to i and i to x
 */


#include <iostream>
#include <queue>
#include <cstdio>
#define p pair<int, int>
#define vi vector<p>
#define f first
#define s second
#define pb emplace_back
#define mp make_pair
#define sf scanf
#define pf printf
#define pqi priority_queue<p, vector<p>, greater<p>>
using namespace std;
const int N = 1e3 + 10;
const int INF = 2e9 + 10;
vi e[N];
vi o[N];
int n, m, x, d1[N], d2[N];
bool vis1[N], vis2[N];

pqi pq;
// run dij to find x to i
void dij1(int start){
    for(int i = 1;i<=n;i++) d1[i] = INF;
    d1[start] = 0;
    pq.push(mp(0, start));
    while(!pq.empty()){
        p v = pq.top(); pq.pop();
        if(vis1[v.s]) continue;
        vis1[v.s] = true;
        for(p j: e[v.s]){
            if(d1[j.s] > j.f + v.f){
                d1[j.s] = j.f + v.f;
                pq.push(mp(d1[j.s], j.s));
            }
        }
    }
}
// run dij to find i to x
void dij2(int start){
    for(int i = 1;i<=n;i++) d2[i] = INF;
    d2[start] = 0;
    pq.push(mp(0, start));
    while(!pq.empty()){
        p v = pq.top(); pq.pop();
        if(vis2[v.s]) continue;
        vis2[v.s] = true;
        for(p j: o[v.s]){
            if(d2[j.s] > j.f + v.f){
                d2[j.s] = j.f + v.f;
                pq.push(mp(d2[j.s],j.s));
            }
        }
    }
}

int main() {
    sf("%d %d %d", &n, &m, &x);
    for(int i =1;i<=m;i++){
        int a, b, t;
        sf("%d %d %d", &a, &b, &t);
        e[a].pb(mp(t, b));
        o[b].pb(mp(t, a)); // don't put e here!!!!!
    }
    dij1(x);
    dij2(x);
    int ans = 0;
    for(int i = 1;i<=n;i++) ans = max(ans, d1[i] + d2[i]);

    pf("%d", ans);

    return 0;
}
