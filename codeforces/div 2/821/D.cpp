/*
 * Author: Andy Zhu
 * @date    2022-09-19 07:29:30
 * @version 1.0.0
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

// segment tree
#define lc (rt << 1)
#define rc (rt << 1 | 1)

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
template <typename T> using ms = multiset<T>;
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
    template <typename T> inline T lowbit(T x){return x & (- x);}
    template <typename T> inline T gcd(T a, T b){if(a == 0) return b; if(b == 0) return a; return gcd(b, a % b);}
    template <typename T> inline T lcm(T a, T b){return a / gcd(a, b) * b;}
    template <typename T1, typename T2> inline T1 fp(T1 a, T2 b) {T1 c = 1;while(b) {if(b & 1) c *= a;b >>= 1;a = a * a;}return c;}
    template <typename T1, typename T2, typename T3> inline T1 fp(T1 a, T2 b, T3 mod) 
    {T1 c = 1;while(b) {if(b & 1) c = c * a % mod;b >>= 1;a = a * a % mod;}return c;}
    template <typename T> inline bool is_prime(T x){if(x == 1) return false; for(T i = 2; i * i <= x;i++) if(x % i == 0) return false; return true;}
}

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

namespace fast_io {
    int read() {int x = 0, f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();return f ? -x : x;}
    long long readLL() {long long x = 0, f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();return f ? -x : x;}
    template<typename T> T read(T& x) {x = 0; int f = 0; char ch = getchar();while (!isdigit(ch)) f |= ch == '-', ch = getchar();while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();x = f ? -x : x; return x;}
    template<typename T> void print(T x) {if (x < 0) putchar('-'), x = -x;if (x >= 10) print(x / 10);putchar(x % 10 + '0');}
    template<typename T> void print(T x, char let) {print(x), putchar(let);}
}

// using namespaces
using namespace comfun;
using namespace fast_io;

// common variables
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
const unordered_set<int> vowel = {'a', 'e', 'i', 'o', 'u'};

//------------------- start of initialize --------------------
// initialize for all cases
inline void init1(){

}

//-------------------  end of initialize  --------------------

//--------------------- start of program ---------------------

const int N = 5005;
char s[N], t[N];

struct edge {
    int l, r;
    bool operator<(const edge& other) const {
        return (r - l) < (other.r - other.l);
    }
    bool operator>(const edge& other) const {
        return (r - l) > (other.r - other.l);
    }
};

inline void solve(){
    int n = read(), x = read(), y = read();
    vi a, cnt(n + 5), cnt2(n + 5);
    set<int> vis;
    vpii bst;
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for(int i = 1;i<=n;++i) {
        s[i] -= '0', t[i] -= '0';
        if(s[i] != t[i]) {
            a.pb(i);
            vis.ins(i);
        }
    }
    ckmin(x, 2 * y);
    if(a.size() & 1) {
        puts("-1");
        return;
    }
    if(x >= y) { 
        ll ans = y * a.size() / 2;
        if(a.size() == 2) {
            if(abs(a[1] - a[0]) == 1) ans = x;
        }
        print(ans, '\n');
        return;
    }
    vec<edge> e;
    for(int i = 1;i<a.size();++i) {
        if(1ll * (a[i] - a[i - 1]) * x < y)
            e.pb({a[i - 1], a[i]});
    }
    // sort(all(e), [&](edge& a, edge& b) {
    //     return a.l < b.l;
    // });
    // ll ans1 = 0, ans2 = 0;
    // for(auto[l, r] : e) {
    //     if(cnt[l] == 0) {
    //         ans1 += 1ll * (r - l) * x;
    //         ++cnt[l], ++cnt[r];
    //     } else {
    //         ans2 += 1ll * (r - l) * x;
    //         ++cnt2[l], ++cnt2[r];
    //     }
    // }
    // int tot = 0;
    // for(auto x : a) if(!cnt[x]) ++tot;
    // ll ans = ans1 + 1ll * tot * y / 2;
    // tot = 0;
    // for(auto x : a) if(!cnt2[x]) ++tot;
    // ckmin(ans, ans2 + 1ll * tot * y / 2);
    // print(ans, '\n');
    
    ll ans = 0;
    for(auto[l, r] : e) {
        ans += 1ll * (r - l) * x;
        ++cnt[l], ++cnt[r];
        // cout<<l<<' '<<r<<'\n';
    }
    for(auto[l, r] : e) if(cnt[l] == 2 && cnt[r] == 2) {
        ans -= 1ll * (r - l) * x;
        --cnt[l], --cnt[r];
    }
    sort(all(e), greater<edge>());
    for(auto[l, r] : e) if(cnt[l] == 2 || cnt[r] == 2) {
        ans -= 1ll * (r - l) * x;
        --cnt[l], --cnt[r];
    }
    int tot = 0;
    for(auto x : a) if(!cnt[x]) ++tot;
    print(ans + 1ll * tot * y / 2, '\n');
}


//---------------------  end of program  ---------------------


#define doCase 1
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