#include <iostream>
#include <unordered_map>
#include <algorithm>
#define endl "\n"
using ll = long long;
using namespace std;
const int N = 2e3 + 10;
int Map[N][N];
unordered_map<ll, int> MapX, MapY;
ll t;
int n;
struct windows{
    ll x1, x2, y1, y2;
    int c;
}w[N];
ll x[N], y[N];
ll getX[N], getY[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    int xlen = 0;
    int ylen = 0;
    for(int i = 1;i<=n;i++){
        cin>>w[i].x1 >> w[i].y1 >> w[i].x2 >> w[i].y2 >> w[i].c;
        x[++xlen] = w[i].x1;
        x[++xlen] = w[i].x2;
        y[++ylen] = w[i].y1;
        y[++ylen] = w[i].y2;
    }

    // discretization
    sort(x + 1, x + xlen + 1);
    sort(y + 1, y + ylen + 1);
    int len1 = 0;
    int len2 = 0;
    for(int i = 1;i<=xlen;i++){
        if(MapX[x[i]] == 0) {
            MapX[x[i]] = ++len1;
            getX[len1] = x[i];
        }
    }
    for(int i = 1;i<=ylen;i++){
        if(MapY[y[i]] == 0){
            MapY[y[i]] = ++len2;
            getY[len2] = y[i];
        }
    }
    // initializing
    for(int i = 1;i<=n;i++){
        int lx = MapX[w[i].x1];
        int rx = MapX[w[i].x2];
        if(lx > rx) swap(lx, rx);
        int ly = MapY[w[i].y1];
        int ry = MapY[w[i].y2];
        if(ly > ry) swap(ly, ry);
        int c = w[i].c;
        for(int j = lx + 1; j<= rx;j++){
            for(int k = ly + 1; k<= ry;k++){
                Map[j][k] += c;
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i<=len1;i++){
        for(int j = 1;j<=len2;j++){
            if(Map[i][j] >= t){
                ans += (getX[i] - getX[i - 1]) * (getY[j] - getY[j - 1]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
