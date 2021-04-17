#include <iostream>
#include <algorithm>
#define mp make_pair
#define f first
#define s second
#define endl "\n"
using namespace std;
const int N = 2e3 + 10;
typedef pair<int, int> PI;
typedef long long ll;
int n, len = 0;
PI node[N];

struct seg{
    int id1;
    int id2;
    ll dist;
} e[N * N];

struct PII {
    int cur; ll dist;
    int last;
}dp[N];

bool cmp(seg a, seg b){
    return a.dist < b.dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        int x, y;
        cin>>x>>y;
        node[i] = mp(x, y);
        for(int j = 1;j<i;j++){
            e[++len].id1 = i;
            e[len].id2 = j;
            e[len].dist = (node[j].f - x) * (node[j].f - x) + (node[j].s - y) * (node[j].s - y);
        }
    }
    sort(e + 1, e + len + 1, cmp);
    for(int i = 1;i<=n;i++){
        dp[i].cur = 1;
        dp[i].dist = 0;
        dp[i].last = 0;
    }
    int ans = 0;
    for (int i = 1;i<=len;i++){
        int id1 = e[i].id1;
        int id2 = e[i].id2;
        ll dist = e[i].dist;
        int x = dp[id1].cur;
        int y = dp[id2].cur;
        int lastx = dp[id1].last;
        int lasty = dp[id2].last;
        ll prevx = dp[id1].dist;
        ll prevy = dp[id2].dist;
        ll d = node[id1].f * node[id1].f + node[id1].s * node[id1].s;
        ll d2 = node[id2].f * node[id2].f + node[id2].s * node[id2].s;
        if(prevy < dist){
            if(x < y + 1){
                dp[id1].cur = y + 1;
                dp[id1].last = x;
                dp[id1].dist = dist;
            }
        } else {
            if(x < lasty + 1){
                dp[id1].cur = lasty + 1;
                dp[id1].last = x;
                dp[id1].dist = dist;
            }
        }
        if(prevx < dist){
            if(y < x + 1){
                dp[id2].cur = x + 1;
                dp[id2].last = y;
                dp[id2].dist = dist;
            }
        } else {
            if(y < lastx + 1){
                dp[id2].cur = lastx + 1;
                dp[id2].last = y;
                dp[id2].dist = dist;
            }
        }
        if(d > dp[id1].dist) {
            ans = max(ans, dp[id1].cur);
        }
        if(d2 > dp[id2].dist) {
            ans = max(ans, dp[id2].cur);
        }

    }
    cout<<ans<<endl;
    return 0;
}
