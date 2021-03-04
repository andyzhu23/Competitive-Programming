#include <iostream>
#define int long long
using namespace std;
const int N = 1e3;
int dir[8][2] = {{1,2},{2,1},{-1,2},{2,-1},{-2,1},{1,-2},{-1,-2},{-2,-1}};
int x,y,a,b;
int Map[N][N];
bool mark[N][N];

int isOk(int i, int j){
    return i>=0 && j>=0;
}

signed main() {
    cin>>x>>y>>a>>b;
    mark[a][b] = true;
    for(int i = 0;i<8;i++){
        int c = a + dir[i][0];
        int d = b + dir[i][1];
        if(isOk(c,d)) mark[c][d] = true;
    }
    for(int i = 0;i<N;i++){
        if(mark[i][0]) break;
        Map[i][0] = 1;
    }
    for(int i = 0;i<N;i++){
        if(mark[0][i]) break;
        Map[0][i] = 1;
    }
    for(int i = 1;i<=x;i++){
        for(int j = 1;j<=y;j++){
            if(!mark[i][j]) {
                Map[i][j] += Map[i-1][j];
                Map[i][j] += Map[i][j-1];
            }
        }
    }
    cout<<Map[x][y];
    return 0;
}
