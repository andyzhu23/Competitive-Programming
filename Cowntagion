#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5+32;
int n,ans = 0,a,b;

vector<int> road[N];
bool vis[N];
queue<int> q;

int main() {
    cin>>n;
    for(int i = 1;i<=n-1;i++){
        cin>>a>>b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    q.push(1);
    vis[1] = true;
    int cur;
    while(!q.empty()){

        cur = q.front(); q.pop();
        vis[cur] = true;
        if(cur!=1) ans++;
        int cow =1;

        int total = road[cur].size();
        for(int i = 0;i<road[cur].size();i++){
            if(!vis[road[cur][i]]){
                q.push(road[cur][i]);
            }else total --;
        }
        while(cow <= total){
            cow*=2;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
