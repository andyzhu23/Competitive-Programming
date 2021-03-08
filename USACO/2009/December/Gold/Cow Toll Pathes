/*
 * so for this question, we can use Floyd algorithm to get all distance, but we need to take account of
 * the value of c. We don't know for sure which point of c that the path went through is the greatest.
 * Therefore, we can sort the c array from smallest to greatest. Then enumerate the new array and because we know that
 * the current c value that we enumerate is guaranteed to be the smallest, we take the shortest possible distance
 * and add by the maximum value of c[j], c[i] and the point we enumerated and that should give us the minimum value.
 */


#include <iostream>
#include <algorithm>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
typedef pair<int,int> p;
const int N = 260;
const int INF = 1e9 + 10;
p c[N];
int n, m, K;
int cost[N][N], dist[N][N], C[N];

signed main() {
    cin>>n>>m>>K;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dist[i][j] = INF;
            cost[i][j] = INF;
        }
        dist[i][i] = cost[i][i] = 0;
    }
    for(int i = 1;i<=n;i++){
        cin>>c[i].f;
        c[i].s = i;
        C[i] = c[i].f;
    }

    for(int i = 1;i<=m;i++){
        int a, b, w;
        cin>> a>>b >>w;
        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = min(dist[b][a], w);
    }

    sort(c + 1, c + n + 1);

//    for(int k = 1;k<=n;k++){
//        int pos = c[k].s;
//        for(int i = 1;i<=n;i++){
//            for(int j = 1;j<=n;j++){
//                if(dist[i][j] > dist[i][pos] + dist[pos][j]){
//                    dist[i][j] = dist[i][pos] + dist[pos][j];
//                }
//            }
//        }
//    }

    for(int k = 1;k<=n;k++){
        int pos = c[k].s;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                //if(i ==j) continue;
                //if(pos == i || pos == j) continue;
                if(dist[i][j] > dist[i][pos] + dist[pos][j]){
                    dist[i][j] = dist[i][pos] + dist[pos][j];//do not calculate dist separately
                }
                cost[i][j] = min(cost[i][j], dist[i][pos] + dist[pos][j] + max(C[i], max(C[j], C[pos])));
//                if(i == 1 && j == 4){
//                    cout<<cost[i][j]<<" "<<pos<<" " <<dist[i][pos]<<" "<<dist[pos][j]<<" " << pos<<endl;
//                }
            }
        }
    }
    for(int i = 1;i<=K;i++){
        int a,b;
        cin>>a>>b;
        cout<< cost[a][b] <<endl;
    }
    return 0;
}
