/*
 * use two arrays to determine how many times a tile had been swapped in order to determine its color
 */

#include <iostream>
using namespace std;
const int N =5e6 + 10;
int m, n, k;

bool e[N], f[N];

int main() {
    cin>>m>>n>>k;
    //bool e[m][n];

    for(int i = 1;i<=k;i++){
        char c;
        int a;
        cin>>c >>a;
        if(c == 'R'){
            e[a] = !e[a];
        } else {
            f[a] = !f[a];
        }
    }
    int ans = 0;
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(e[i] && f[j]) continue;
            if(e[i] || f[j] && !(e[i] && f[j])) ans++;
        }
    }
    cout<<ans;
    return 0;
}
