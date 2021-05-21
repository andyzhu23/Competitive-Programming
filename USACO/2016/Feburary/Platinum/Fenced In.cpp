/*
 * Author: Andy Zhu
 */

// include
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

// define
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
#define ALL(v) v.begin(), v.end()

// using
using ll = long long;
using lb = long double;
using namespace std;

// typedef
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

// common variables
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};

// common functions
inline int lowbit(int x){return x & (- x);}
inline bool CMP(int a, int b){return a > b;}
inline void copy(int a[], int b[], int sz){for(int i = 0;i<=sz;i++) a[i] = b[i];}
inline int gcd(int a, int b){if(a == 0) return b; if(b == 0) return a; return gcd(b, a % b);}
inline int lcm(int a, int b){return a / gcd(a, b) * b;}
inline int getMid(int l, int r){return (l + r) >> 1;}
inline ll fast_pow(ll a, ll b){if(b == 1) return a;ll tmp = fast_pow(a, b / 2);if(b % 2 == 1) return tmp * tmp * a;else return tmp * tmp;}
inline bool is_prime(ll x){for(ll i = 2; i * i <= x;i++) if(x % i == 0) return false; return true;}

//---------------------End of Template---------------------

int n, m, A, B;

int main(){
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    cin>>A>>B>>n>>m;
    VI ha(m + 1);
    VI va(n + 1);
    for(int i = 0;i<n;i++) cin>>va[i];
    for(int i = 0;i<m;i++) cin>>ha[i];
    sort(ALL(ha));
    sort(ALL(va));
    for(int i = 0;i<n;i++) va[i] = va[i + 1] - va[i];
    for(int i = 0;i<m;i++) ha[i] = ha[i + 1] - ha[i];
    va[n] = B - va[n];
    ha[m] = A - ha[m];
    sort(ALL(va));
    sort(ALL(ha));
    n++, m++;
    int vi = 0, hi = 0;
    ll ans = 1ll * va[vi ++] * (m - 1) + 1ll * ha[hi ++] * (n - 1);
    while(vi < n && hi < m){
        if(va[vi] < ha[hi])
            ans += va[vi++] * (m - hi);
        else 
            ans += ha[hi++] * (n - vi);
    }
    cout<<ans<<endl;
    return 0;
}
