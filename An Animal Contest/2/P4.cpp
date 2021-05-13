/*
 * Author: Andy Zhu
 *
 * just a noob, what is coding?
 *
 * “Do we run the trails, or the trails run us? Get revenge on the trails that ran u like that”
 * I pray the cows
 * My Dream School:
 * South Harmon Institute of Technology
 * The meaning of life is:
 * #define int long long
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory>
#include <memory.h>
#include <string>
#include <algorithm>
#include <bitset>
#include <iterator>
#include <deque>
#include <random>
#define endl "\n"
#define l_b lower_bound
#define u_b upper_bound
#define ins insert
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define pb push_back
#define pf push_front
#define mp make_pair
#define random(a, b) rand() % (b - a + 1) + a
#define log(a, b) log(a) / log(b)
#define UM unordered_map;
#define US unordered_set;
#define V vector;
using ll = long long;
using lb = long double;
using namespace std;
typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef pair<string, string> PS;
typedef vector<int> VI;
typedef vector<PI> VPI;
typedef vector<ll> VLL;
typedef vector<PLL> VPLL;
typedef queue<int> QI;
typedef stack<int> STKI;
typedef deque<int> DQI;
typedef set<int> SI;
typedef set<ll> SLL;
typedef set<string> SS;
typedef unordered_set<int> USI;
typedef unordered_set<ll> USLL;
typedef unordered_set<string> USS;
typedef map<int, int> MI;
typedef map<ll, ll> MLL;
typedef map<string, string> MS;
typedef unordered_map<int, int> UMI;
typedef unordered_map<ll, ll> UMLL;
typedef unordered_map<string, string> UMS;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};

inline bool CMP(int a, int b){
    return a > b;
}

inline void copy(int a[], int b[], int sz){
    for(int i = 0;i<=sz;i++)
        a[i] = b[i];
}

inline int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}

inline int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

inline int getMid(int l, int r){
    return (l + r) >> 1;
}

inline ll fast_pow(ll a, ll b){
    if(b == 1) return a;
    ll tmp = fast_pow(a, b / 2);
    if(b % 2 == 1) return tmp * tmp * a;
    else return tmp * tmp;
}

inline bool is_prime(ll x){
    for(ll i = 2; i * i <= x;i++){
        if(x % i == 0) return false;
    }
    return true;
}

const int N = 1510;
int a[N][N], n, m, sum[N][N];
bool vis[N][N], flag;

inline bool check(int x, int y, int sz){
    int x2 = x + sz - 1;
    int y2 = y + sz - 1;
    return sum[x2][y2] - sum[x - 1][y2] - sum[x2][y - 1] + sum[x - 1][y - 1] == 0;
}

inline void dfs(int x, int y, int sz){
    if(x + sz - 1 > n || y + sz - 1 > m || x <= 0 || y <= 0) return;
    if(flag) return;
    if(x + sz - 1 == n && y + sz - 1 == m){
        flag = true;
        return;
    }
    if(vis[x][y]) return;
    vis[x][y] = true;
    if(!check(x, y, sz)) return;
    for(int i = 0;i<4;i++){
        dfs(x + dir[i][0], y + dir[i][1], sz);
    }
}

inline bool ok(int sz){
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            vis[i][j] = 0;
        }
    }
    flag = false;
    dfs(1, 1, sz);

    if(flag) return true;
    else return false;
}

int main(){
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            char x;
            cin>>x;
            if(x == 'O') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    int l = 1, r = min(n, m), ans = 0;
    while(l <= r){
        int mid = getMid(l, r);
        if(ok(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout<<ans<<endl;
    return 0;
}
