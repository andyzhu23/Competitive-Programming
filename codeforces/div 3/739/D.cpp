/*
 * Author: Andy Zhu
 * @date    2021-08-18 07:33:39
 * @version 1.0.0
 */

//include
#include <bits/stdc++.h>
using namespace std;

// define
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define mp make_pair
#define random(a, b) rand() % (b - a + 1) + a
#define log(a, b) log(a) / log(b)
#define ALL(v) v.begin(), v.end()
#define clr(x) memset(x, 0, sizeof(x))
#define setINF(x) memset(x, 63, sizeof(x))
#define setNINF(x) memset(x, -63, sizeof(x))

// Data Structure Shorten
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using stki = stack<int>;
template <typename T> using vec = vector<T>;
template <typename T> using us = unordered_set<T>;
template <typename T> using os = set<T>;
template <typename T1, typename T2> using um = unordered_map<T1, T2>;
template <typename T1, typename T2> using om = map<T1, T2>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vec<T>, greater<T> >;
using vi = vec<int>;
using vpii = vec<pii>;
using vll = vec<ll>;
using vpll = vec<pll>;
using vb = vec<bool>;

// loops!
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

// common variables
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
struct Edge {int u, v, w;};

// common functions
template <typename T> inline void cmax(T& u, T v) { u = max(u, v); }
template <typename T> inline void cmin(T& u, T v) { u = min(u, v); }

template <typename T> inline T lowbit(T x){return x & (- x);}
template <typename T> inline T gcd(T a, T b){if(a == 0) return b; if(b == 0) return a; return gcd(b, a % b);}
template <typename T> inline T lcm(T a, T b){return a / gcd(a, b) * b;}
template <typename T1, typename T2> inline T1 fast_pow(T1 a, T2 b)
{if(b == 1) return a; T1 tmp = fast_pow(a, b >> 1); if(b & 1) return tmp * tmp * a; else return tmp * tmp;}
template <typename T1, typename T2, typename T3> inline T1 fast_pow(T1 a, T2 b, T3 m)
{if(b == 1) return a % m; T1 tmp = fast_pow(a, b >> 1, m); if(b & 1) return tmp * tmp % m * a % m; else return tmp * tmp % m;}
template <typename T> inline bool is_prime(T x){if(x == 1) return false; for(T i = 2; i * i <= x;i++) if(x % i == 0) return false; return true;}

template <typename T> inline void debugArray(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
template <typename T> inline void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}


//------------------- start of initialize -------------------
// initialize for all cases

inline void init1(){

}

// initialize for the current subcase
inline void init2(){

}

//-------------------  end of initialize  -------------------

//--------------------- start of program ---------------------


inline void solve(){
    int n; cin>>n;
    int ans = INF;
    ll prev = 0;
    for(int i = 0;i<63;i++) {
        ll cur = prev * 2;
        if(cur == 0) cur ++;
        string N = to_string(n);
        string CUR = to_string(cur);
        int cnt = 0;
        int pre = 0;
        int pre2 = 0;
        bool ok[60] = {0};
        int save = 0;
        if(i == 8) {
            i++;
            i--;
        }
        for(int i = 0;i<CUR.size();i++) {
            for (int j = pre; j < N.size(); j++) {
                if (CUR[i] == N[j]) {
                    if(!ok[i] && i >= 1) {
                        save = 0;
                        break;
                    }
                    ok[i + 1] = 1;
                    save++;
                    cnt = max(save, cnt);
                    pre = j + 1;
                    break;
                }
            }
        }
        prev = cur;
        //cout<<cur<<" "<<abs(int(N.size() - CUR.size())) + min(int(N.size()), int(CUR.size())) * 2 - cnt * 2 <<'\n';
        ans = min(ans, abs(int(N.size() - CUR.size())) + min(int(N.size()), int(CUR.size())) * 2 - cnt * 2);
        if(ans == 7) {
            ans++;
            ans--;
        }
    }
    cout<<ans<<'\n';
}


//---------------------  end of program  ---------------------


#define doCase 1
#define config 0
#define kickstart 0
#define unsync 1

inline void setIO() {
    #if config
    // configuration here
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    #if unsync
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #endif
}

signed main(){
    setIO();
    init1();
    srand(time(0));
    #if doCase
    int t; cin>>t;
    for(int i = 1;i<=t;i++) {
        if(kickstart) cout<<"Case #"<< i<<": ";
        init2();
        solve();
    }
    #else
    solve();
    #endif
    string jack = "Jack is always within you";
    // 84ecef820ae07338
    return 0;
}


/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/