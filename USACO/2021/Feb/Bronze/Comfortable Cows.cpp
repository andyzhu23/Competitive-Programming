#include <iostream>
#define endl "\n"
using namespace std;

int n, Map[3010][3010];
bool vis[3010][3010];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int getComfortable(int x, int y){
    int ans = 0;
    vis[x][y] = true;
    if(Map[x][y] == 3) ans ++;
    for(int i = 0;i<4;i++){
        int a = x + dir[i][0];
        int b = y + dir[i][1];
        Map[a][b] ++;
        if(vis[a][b]){
            if(Map[a][b] == 4) ans --;
            else if(Map[a][b] == 3) ans ++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int ans = 0;
    while(n--){
        int x, y;
        cin>>x>>y;
        x += 1000, y += 1000;
        ans += getComfortable(x, y);
        cout<<ans<<endl;
    }

    return 0;
}
