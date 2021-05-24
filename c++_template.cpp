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
#define clear(x) memset(x, 0, sizeof(x));

// using
using namespace std;

using ll = long long;
using lb = long double;
using PI = pair<int, int>;
using PLL = pair<ll, ll>;
using PS = pair<string, string>;
using VI = vector<int>;
using VPI = vector<PI>;
using VLL = vector<ll>;
using VPLL = vector<PLL>;
using QI = queue<int>;
using PQI = priority_queue<int>;
using PQII = priority_queue<int, VI, greater<int>>;
using STKI = stack<int>;
using DQI = deque<int>;
using SI = set<int>;
using SLL = set<ll>;
using SS = set<string>;
using USI = unordered_set<int>;
using USLL = unordered_set<ll>;
using USS = unordered_set<string>;
using MI = map<int, int>;
using MLL = map<ll, ll>;
using MS = map<string, string>;
using UMI = unordered_map<int, int>;
using UMLL = unordered_map<ll, ll>;
using UMS = unordered_map<string, string>;

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

int main(){
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    
    return 0;
}
