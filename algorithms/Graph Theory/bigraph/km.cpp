#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define ALL(v) v.begin(), v.end()
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
const int INF = 0x7f7f7f7f;
const int N = 310;
vpii e[N];
int n, d, match[N], lv[N], rv[N];
bool visx[N], visy[N];

bool Find(int u) {
    visx[u] = 1;
    for(pii v : e[u]) {
        if(visy[v.fir]) continue;
        if(lv[u] + rv[v.fir] - v.sec == 0) {
            visy[v.fir] = 1;
            if(match[v.fir] == 0 || Find(match[v.fir])) {
                match[v.fir] = u;
                return 1;
            }
        } else if(lv[u] + rv[v.fir] - v.sec > 0) d = min(d, lv[u] + rv[v.fir] - v.sec);
    }
    return 0;
} 

bool cmp(pii a, pii b) {
    return a.sec > b.sec;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            int x; cin>>x;
            e[i].pb(mp(j, x));
        }
    }
    for(int i = 1;i<=n;i++) {
        sort(ALL(e[i]), cmp);
        lv[i] = e[i][0].sec;
    }
    for(int i = 1;i<=n;i++) {
        while(1) {
            d = INF;
            memset(visy, 0, sizeof(visy));
            memset(visx, 0, sizeof(visx));
            if(Find(i)) break;
            for(int i = 1;i<=n;i++) {
                lv[i] -= visx[i] ? d : 0;
                rv[i] += visy[i] ? d : 0;
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) ans += lv[i] + rv[i];
    cout<<ans<<"\n";
    return 0;
}
