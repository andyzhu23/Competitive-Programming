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
#define UM unordered_map;
#define US unordered_set;
#define V vector;
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

const int N = 10;
int n;
VI a(N), b(N);
queue<VI> q;
unordered_set<string> vis;

inline bool isOk(int A, int B) {
    if (A == 0 && B == 0) return false;
    return true;
}

inline void move(VI& nxt, int A, int B) {
    if (nxt[B] == 0) {
        nxt[B] = nxt[A] % 10;
        nxt[A] /= 10;
        return;
    }
    else if (nxt[A] == 0) {
        nxt[A] = nxt[B] % 10;
        nxt[B] /= 10;
        return;
    }
    int a = nxt[A] % 10;
    int b = nxt[B] % 10;
    if (a < b) {
        nxt[B] = nxt[B] * 10 + a;
        nxt[A] /= 10;
    }
    else {
        nxt[A] = nxt[A] * 10 + b;
        nxt[B] /= 10;
    }
}

inline bool Visited(VI& nxt) {
    string cur;
    for (int i = 1; i <= n; i++) cur += "|" + to_string(nxt[i]);
    cur += "|";
    if (vis.count(cur)) return true;
    vis.ins(cur);
    return false;
}

inline bool isAns(VI& cur){
    for(int i = 1;i<=n;i++){
        if(cur[i] != i) return false;
    }
    return true;
}

inline void solve() {
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b.begin() + 1, b.begin() + n + 1);
    q.push(a);
    while (!q.empty()) {
        VI cur = q.front();
        q.pop();
        if(isAns(cur)) {
            cout << cur[n + 1] << endl;
            return;
        }
        for (int i = 1; i < n; i++) {
            if (isOk(cur[i], cur[i + 1])) {
                VI nxt(10);
                for (int j = 0; j < N; j++) nxt[j] = cur[j];
                move(nxt, i, i + 1);
                if (Visited(nxt)) continue;
                nxt[n + 1]++;
                q.push(nxt);
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true) {
        cin>>n;
        if (n == 0) break;
        vis.clear();
        while(!q.empty()) q.pop();
        fill(ALL(a), 0);
        fill(ALL(b), 0);
        solve();
    }
}
