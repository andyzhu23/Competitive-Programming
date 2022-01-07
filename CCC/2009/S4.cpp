#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    vector<vector<pair<int,int>>> v(n+1);
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    vector<pair<int,int>> pencils;
    int k;
    cin>>k;
    while(k--){
        int x,y;
        cin>>x>>y;
        pencils.push_back({x,y});
    }
    int d;
    cin>>d;
    int dist[n+1];
    for(int i=0; i<=n; i++) dist[i]=1e9;
    dist[d]=0;
    queue<pair<int,int>> q;
    q.push({d,0});
    while(!q.empty()){
        int node=q.front().f;
        q.pop();
        for(auto p:v[node]){
            if(dist[node]+p.s < dist[p.f]){
                dist[p.f] = dist[node]+p.s;
                q.push(p);
            }
        }
    }
    int ans=1e9;
    for(auto p:pencils){
        ans=min(ans,dist[p.f]+p.s);
    }
    cout<<ans<<'\n';
}
