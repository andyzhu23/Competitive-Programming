/*
 * Author: Andy Zhu
 */

//include
#include <bits/stdc++.h>
using namespace std;

// define
#define endl "\n"
#define l_b lower_bound
#define u_b upper_bound
#define ins insert
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define ep emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define mp make_pair
#define random(a, b) rand() % (b - a + 1) + a
#define log(a, b) log(a) / log(b)
#define ALL(v) v.begin(), v.end()
#define clr(x) memset(x, 0, sizeof(x));
#define setINF(x) memset(x, 63, sizeof(x));

// Data Structure Shorten
using ll = long long;
using ull = unsigned long long;
using lb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using qi = queue<int>;
using stki = stack<int>;
template <typename T> using vec = vector<T>;
template <typename T> using uset = unordered_set<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using pq = priority_queue<T>; 
template <typename T> using pqg = priority_queue<T, vec<T>, greater<T> >;
using vi = vec<int>;
using vpii = vec<pii>;
using vll = vec<ll>;
using vpll = vec<pll>;

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
template <typename T> inline T getMid(T l, T r){return (l + r) >> 1;}
template <typename T1, typename T2> inline T1 fast_pow(T1 a, T2 b){if(b == 1) return a; T1 tmp = fast_pow(a, b / 2); if(b % 2 == 1) return tmp * tmp * a; else return tmp * tmp;}
template <typename T> inline bool is_prime(T x){if(x == 1) return false; for(T i = 2; i * i <= x;i++) if(x % i == 0) return false; return true;}

template <typename T> inline void debugArray(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
template <typename T> inline void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}


//------------------- start of initialize -------------------

inline void init1(){
    // initialize for all cases

}

inline void init2(){
    // initialize for the current subcase

}

//-------------------  end of initialize  -------------------

//--------------------- start of program ---------------------


inline void solve(){
    
}


//---------------------  end of program  ---------------------


bool doCase = 0;
bool config = 0;
bool kickstart = 0;

int main(){
    if(config){
        // configuration here
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    }
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init1();
    if(doCase) {
        int t; cin>>t;
        for(int i = 1;i<=t;i++) {
            if(kickstart) cout<<"Case #"<< i<<": ";
            init2();
            solve();
        }
    } else solve();
    string jack = "Jack is always within you";
    return 0;
}
