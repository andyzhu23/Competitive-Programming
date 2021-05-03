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

const int N = 100;
string l[5], r[5];
string s, d;
int n, L, R;
string ans[N];
string ans2[N];
bool flag;

unordered_map <string, vector<string> > vis;

inline void dfs(string a, int step){
    if(step == L + 1){
        for(int i = 1;i<=step;i++){
            vis[a].pb(ans[i]);
        }
        return;
    }
    for(int i = 0;i<a.size();i++){
        for(int j = 1;j<=3;j++){
            if(i + l[j].size() <= a.size() && a.substr(i, l[j].size()) == l[j]){
                string b = "";
                b = a.substr(0, i) + r[j];
                if(i + l[j].size() < a.size())
                    b += a.substr(i + l[j].size(), a.size() - l[j].size() - i);
                ans[step] = to_string(j) + " " + to_string(i + 1) + " " + b;
                dfs(b, step + 1);
            }
        }
    }
}

inline void dfs2(string a, int step){
    if(flag) return;
    if(step == L){
        if(vis[a].empty()) return;
        for(int i = 0;i<L;i++){
            cout<<vis[a][i]<<endl;
        }
        for(int i = L + 1;i <= n;i++){
            cout<<ans[i]<<endl;
        }
        flag = true;
    }
    for(int i = 0;i<a.size();i++){
        for(int j = 1;j<=3;j++){
            if(i + r[j].size() <= a.size() && a.substr(i, r[j].size()) == r[j]){
                string b = "";
                b = a.substr(0, i) + l[j];
                if(i + r[j].size() < a.size())
                    b += a.substr(i + r[j].size(), a.size() - r[j].size() - i);
                ans[step] = to_string(j) + " " + to_string(i + 1) + " " + a;
                dfs2(b, step - 1);
            }
        }
    }

}

int main(){
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1;i<=3;i++){
        cin>>l[i]>>r[i];
    }
    cin>>n>>s>>d;
    L = n % 2 == 0 ? n / 2 : n / 2 + 1;
    dfs(s, 1);
    dfs2(d, n);
    return 0;
}
