#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
const int N = 1e4 + 10;
int n, f[N];

vector<int> e[N];
typedef pair<int, int> p;

int Find(int x){
    if(f[x] == x) return x;
    return f[x] = Find(f[x]);
}

int bfs(int u, int v){
    queue<p> q;
    unordered_set<int> vis;
    q.push(make_pair(u, -1));
    while(!q.empty()){
        p a = q.front(); q.pop();
        int x = a.first;
        if(x == v){
            return a.second;
        }
        for(int i = 0;i<e[x].size();i++){
            int y = e[x][i];
            if(vis.count(y)) continue;
            q.push(make_pair(y, a.second + 1));
        }
    }
    return 0;
}

int main() {
    cin>>n;
    for(int i = 1;i<N;i++) f[i] = i;
    int u, v;
    int fu, fv;
    for(int i = 1;i<=n;i++){
        cin>>u>>v;
        fu = Find(u);
        fv = Find(v);
        f[fu] = fv;
        e[u].push_back(v);

    }
    while(true){
        cin>>u>>v;
        if(u == 0 && v == 0) break;
        fu = Find(u);
        fv = Find(v);
        if(fu == fv){
            int ans = bfs(u, v);
            cout<<"Yes "<<ans<<endl;
        } else {
            cout<<"No"<<endl;
        }

    }
    return 0;
}
