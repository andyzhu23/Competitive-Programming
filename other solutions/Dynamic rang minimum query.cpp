/*
 * Author: Andy Zhu
 */

#include <iostream>
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
#include <string>
#include <algorithm>
#include <bitset>
#include <iterator>
#include <deque>
#define endl "\n"
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define pb push_back
#define pf push_front
#define mp make_pair
#define random(a, b) rand() % (b - a + 1) + a
#define log(a, b) log(a) / log(b)
using ll = long long;
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

inline int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a % b);
}

inline int lcm(int a, int b){
    return a * b / gcd(a, b);
}

inline int getMid(int l, int r){
    return (l + r) >> 1;
}

inline int fast_pow(ll a, ll b){
    if(b == 1) return a;
    ll tmp = fast_pow(a, b / 2);
    if(a % 2 == 1) return tmp * tmp * a;
    else return tmp * tmp;
}

inline bool is_prime(ll x){
    for(ll i = 2; i * i <= x;i++){
        if(x % i == 0) return false;
    }
    return true;
}

const int N = 1e6 + 10;
int st[N << 2];

inline void push_up(int rt){
    st[rt] = min(st[lc], st[rc]);
}

inline void build(int rt, int l, int r){
    if(l == r){
        cin>>st[rt];
        return;
    }
    int mid = getMid(l, r);
    build(lc, l, mid);
    build(rc, mid + 1, r);
    push_up(rt);
}

inline void update(int rt, int l, int r, int pos, int val){
    if(l == r){
        st[rt] = val;
        return;
    }
    int mid = getMid(l, r);
    if(pos<=mid) update(lc, l, mid, pos, val);

    else update(rc, mid + 1, r, pos, val);
    push_up(rt);
}

inline int query(int rt, int l, int r, int x, int y){
    if(l == x && y == r){
        return st[rt];
    }
    int mid = getMid(l, r);
    if(y <= mid) return query(lc, l, mid, x, y);
    else if(x > mid) return query(rc, mid + 1, r, x, y);
    else return min(query(lc, l, mid, x, mid), query(rc, mid + 1, r, mid + 1, y));
}

int n, m;

inline void solve(){
    char opt;
    int a, b;
    cin>>opt>>a>>b;
    if(opt == 'M'){
        update(1, 1, n, ++a, b);
    } else {
        cout<<query(1, 1, n, ++a, ++b)<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    build(1, 1, n);
    while(m--){
        solve();
    }
    return 0;
}
