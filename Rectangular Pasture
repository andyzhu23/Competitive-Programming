#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> cow;
int n;
cow cows[2504];
map<long long, long long> xkey,ykey;
long long Map[2504][2504];

bool cmp(cow a, cow b){
    return a.second<b.second;
}

int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>cows[i].first>>cows[i].second;
    }
    sort(cows+1, cows+n+1);

    for(int i = 1;i<=n;i++){
        xkey[cows[i].first] = i;
    }
    sort(cows+1, cows+n+1, cmp);
    for(int i = 1;i<=n;i++){
        ykey[cows[i].second] = i;
        cows[i].first = xkey[cows[i].first];
        cows[i].second = ykey[cows[i].second];
        Map[cows[i].first][cows[i].second] = 1;

    }
    sort(cows+1, cows+n+1);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            Map[i][j] = Map[i][j-1] + Map[i-1][j] - Map[i-1][j-1] + Map[i][j];
        }
    }
    long long ans = 1;
    long long above;
    long long bellow;
    cow x,y;
    for(int i = 1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            x = make_pair(cows[i].first,cows[i].second);
            y = make_pair(cows[j].first,cows[j].second);

            if(x.first>y.first) continue;

            if(x.second<y.second) {
                above = Map[y.first][n] - Map[y.first][y.second] - Map[x.first][n] + Map[x.first][y.second] + 1;
                bellow = Map[y.first][x.second - 1] - Map[x.first][x.second - 1] + 1;
            } else {
                above = Map[y.first][n] - Map[y.first][x.second] - Map[x.first][n] + Map[x.first][x.second] + 1;
                bellow = Map[y.first][y.second - 1] - Map[x.first][y.second - 1] + 1;
            }
            ans += above * bellow;
        }
    }
    cout<<ans;

    return 0;
}
