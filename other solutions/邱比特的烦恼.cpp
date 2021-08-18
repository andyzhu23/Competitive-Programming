#include <bits/stdc++.h>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define getDist(i, j) ll(boy[i].x - girl[j].x) * ll(boy[i].x - girl[j].x) + ll(boy[i].y - girl[j].y) * ll(boy[i].y - girl[j].y)
#define slope(i, j) double(i.y - j.y) / double(i.x - j.x)
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int INF = 0x3f3f3f3f;
const int N = 40;
struct person {
    int x, y, id;
} boy[N], girl[N];

unordered_map<string, int> MapB, MapG;

bool visx[N], visy[N], visX[N], visY[N];

int power[N][N], n, k, d, l[N], r[N], match[N];
vector<pii> e[N];

bool cmp(pii a, pii b) {return a.sec > b.sec;}

bool ok(person a, person b, person c) {
    return !((max(a.x, b.x) >= c.x && min(a.x, b.x) <= c.x && max(a.y, b.y) >= c.y && min(a.y, b.y) <= c.y) && (slope(a, c) == slope(c, b)));
}

bool Find(int u) {
    visx[u] = 1;
    for(pii& cur : e[u]) {
        int& v = cur.fir;
        int& w = cur.sec;
        if(visy[v]) continue;
        if(l[u] + r[v] == w) {
            visy[v] = 1;
            if(match[v] == 0 || Find(match[v])) {
                match[v] = u;
                return 1;
            }
        } else d = min(d, l[u] + r[v] - w);
    }
    return 0;
}

void km() {
    for(int i = 1;i<=n;i++) {
        while(1) {
            d = INF;
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            if(Find(i)) break;
            for(int i = 1;i<=n;i++) {
                if(visx[i]) l[i] -= d;
                if(visy[i]) r[i] += d;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k >> n;
    for(int i = 1;i<=n;i++) {
        string name;
        cin>>boy[i].x >>boy[i].y>>name;
        for(char& c : name) c = tolower(c);
        boy[i].id = i;
        MapB[name] = i;
    }
    for(int i = 1;i<=n;i++) {
        string name;
        cin>>girl[i].x >> girl[i].y>>name;
        for(char& c : name) c = tolower(c);
        girl[i].id = i;
        MapG[name] = i;
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            power[i][j] = (getDist(i, j) <= k * k) ? 1 : 0;
            for(int k = 1;k<=n;k++) {
                if(!power[i][j] || ((!ok(boy[i], girl[j], boy[k])) && k != i) || ((!ok(boy[i], girl[j], girl[k])) && k != j)) power[i][j] = 0;
            }
        }
    }
    while(1) {
        string a, b;
        int c;
        cin>>a;
        for(char& ch : a) ch = tolower(ch);
        if(a == "end") break;
        cin>>b>>c;
        for(char& ch : b) ch = tolower(ch);
        if(MapB[a] == 0) swap(a, b);
        power[MapB[a]][MapG[b]] = power[MapB[a]][MapG[b]] ? c : 0;
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++)
            if(power[i][j]) e[i].pb(mp(j, power[i][j]));
        sort(ALL(e[i]), cmp);
        l[i] = e[i][0].sec;
    }
    km();
    int ans = 0;
    for(int i = 1;i<=n;i++) {
        if(match[i]) ans += power[match[i]][i];
    }
    cout<<ans<<"\n";
    return 0;
}

