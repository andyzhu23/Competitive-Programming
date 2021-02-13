#include <iostream>
#include <queue>
using namespace std;
const int N = 1e3+10;
const int VIS = 1e7;
int m,n;
int Map[N][N];
int vis[VIS];
queue<int> q;

bool isOk(int a, int b){
    return 0<a && a<=m && b>0 && b<=n;
}

int main() {
    cin>>m>>n;
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            cin>>Map[i][j];
        }
    }
    q.push(Map[1][1]);
    int cur;
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(vis[cur]) continue;
        vis[cur] = true;
        for(int i = 1;i*i<=cur;i++){
            if(cur%i == 0){
                if(isOk(i,cur/i)) q.push(Map[i][cur/i]);
                if(isOk(cur/i,i)) q.push(Map[cur/i][i]);
            } if((i == m && cur/i == n) || (cur/i == m && i == n)){
                cout<<"yes";
                return 0;
            }
        }
    }
    cout<<"no";
    return 0;
}
