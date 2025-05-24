/*
 * Author: Andy Zhu
 * @date    ${date}
 * @version ${6:1.0.0}
 */

// optimize
#pragma GCC optimize(2)

//include
#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T>
// using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// template <typename T>
// using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

// pairs
#define fir first
#define sec second

// STL Data Structures
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()
#define ins insert
#define lb lower_bound
#define ub upper_bound

// random
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a, b) rng() % (b - a + 1) + a

// Data Structure Shorten
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
template <typename T> using vec = vector<T>;
template <typename T> using us = unordered_set<T>;
template <typename T> using os = set<T>;
template <typename T1, typename T2> using um = unordered_map<T1, T2>;
template <typename T1, typename T2> using om = map<T1, T2>;
template <typename T> using pq = priority_queue<T>; 
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T> >;
using vi = vector<int>;
using vpii = vector<pair<int, int> >;
using vll = vector<long long>;
using vpll = vector<pair<long long, long long> >;
using vb = vector<bool>;

// common functions

namespace comfun {
    template <typename T1, typename T2> inline void ckmax(T1& u, T2 v) { u = max(u, v); }
    template <typename T1, typename T2> inline void ckmin(T1& u, T2 v) { u = min(u, v); }
    template <typename T1, typename T2, typename T3> inline T1 fp(T1 a, T2 b, T3 mod) 
    {T1 c = 1;while(b) {if(b & 1) c = c * a % mod;b >>= 1;a = a * a % mod;}return c;}
    template <typename T1, typename T2> inline T1 fp(T1 a, T2 b) 
    {if(b == 1) return a;T1 tmp = fp(a, b >> 1);if(b & 1) return tmp * tmp * a;else return tmp * tmp;}
}

#ifndef ONLINE_JUDGE
template<typename T>
concept Printable = requires(T a) { { cerr << a }; };

struct Debug {
    template<typename T, typename U>
    Debug& operator<<(const pair<T, U>& a) { *this << '(' << a.first << ", " << a.second << ')'; return *this; }
    Debug& operator<<(const char& a) { cerr << '\'' << a << '\''; return *this; }
    Debug& operator<<(const string& a) { cerr << '\"' << a << '\"'; return *this; }
    template<Printable T>
    Debug& operator<<(const T& a) { cerr << boolalpha << a; return *this; }
    template<typename T>
    Debug& operator<<(const T& a) {
        cerr << '{';
        for (auto it = begin(a); it != end(a); it++){
            *this << *it;
            if (next(it) != end(a)) { cerr << ", "; }
        }
        cerr << '}';
        return *this;
    }
};

template<typename T, typename... U>
void __print(T t, U... u) { 
    Debug() << t; 
    if constexpr (sizeof...(u)) { 
        cerr << ", "; 
        __print(u...);
    }
}

#define dbg(x...) cerr << "[DEBUG] "<<__func__<<": "<<__LINE__<<", [" << #x << "] = ["; __print(x); cerr << "]" << endl;
#else
#define dbg(x...) ;
#endif

namespace fast_io {
    int read() {int x = 0, f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();return f ? -x : x;}
    long long readLL() {long long x = 0, f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();return f ? -x : x;}
    template <typename T> T read(T& x) {x = 0; int f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();x = f ? -x : x; return x;}
    template <typename T> void print(T x) {if (x < 0) putchar('-'), x = -x;if (x >= 10) print(x / 10);putchar(x % 10 + '0');}
    template <typename T> void print(T x, char let) {print(x), putchar(let);}
}

// using namespaces
using namespace comfun;
using namespace fast_io;

// common variables
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
const unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

//------------------- start of initialize --------------------
// initialize for all cases
inline void init1(){

}

//-------------------  end of initialize  --------------------

//--------------------- start of program ---------------------


inline void solve(){
    
}


//---------------------  end of program  ---------------------


#define doCase 0
#define config LOCAL
// #define kickstart
#define unsync 0

inline void setIO() {
#if config
    // configuration here
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
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
    int t; t = read();
    for(int i = 1;i<=t;i++) {
#ifdef kickstart 
        printf("Case #%d: ", i);
#endif
        solve();
    }
#else 
    solve();
#endif
    string jack = "Jack is always within you";
    return 0;
}

 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/