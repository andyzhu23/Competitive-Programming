#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fir first
#define sec second
const int N = 5e5 + 10;
int e[660][660], o[660][660];
using pii = pair<int, int>;
pii a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;

    for(int i = 1;i<=n;i++) {
        int x, y;
        cin>>x>>y;
        x++, y++;
        a[i] = mp(x, y);
        e[x][y] ++;
        o[x][y] ++;
    }
    for(int i = 1;i<=651;i++) {
        for(int j = 1;j<=651;j++) {
            e[i][j] += e[i][j - 1] + e[i - 1][j] - e[i - 1][j - 1];
        }
    }
    for(int i = 1;i<=n;i++) {
        int x = a[i].fir;
        int y = a[i].sec;
        int tot = (x == 651 ? o[1][y] : 0) + (y == 651 ? o[x][1] : 0);
        cout<<e[651][651] - e[651][y] - e[x][651] + e[x][y] + 1<< " " <<n - e[x - 1][y - 1] - tot<<"\n";
    }

    return 0;
}
