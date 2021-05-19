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


const int N = 1e5 + 10;
int n, q, dep[N], f[N][22], dist[N];

struct node{
	int l, r, dist;
} st[N << 2];

vector<PI> e[N];

inline void dfs(int u, int fa, int d, int sz){
	dep[u] = d;
	f[u][0] = fa;
	for(int i = 1;i<=20;++i)
		f[u][i] = f[f[u][i - 1]][i - 1];
	dist[u] = dist[fa] + sz;
	for(int i = 0;i<e[u].size();i++){
		PI v = e[u][i];
		if(v.fir == fa) continue;
		dfs(v.fir, u, d + 1, v.sec);
	}
}

inline int LCA(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20;i>=0;i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(x == y) return x;
	}
	for(int i = 20;i>=0;i--){
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

inline int getDist(int x, int y){
	int lca = LCA(x, y);
	return dist[x] + dist[y] - 2 * dist[lca];
}

inline void copyNode(int l, int r, int d, node& ans){
	ans.l = l;
	ans.r = r;
	ans.dist = d;
}

inline void push_up(int rt){
	st[rt] = st[lc].dist > st[rc].dist ? st[lc] : st[rc];
	int d = getDist(st[lc].l, st[rc].l);
	if(d > st[rt].dist) copyNode(st[lc].l, st[rc].l, d, st[rt]);
	d = getDist(st[lc].l, st[rc].r);
	if(d > st[rt].dist) copyNode(st[lc].l, st[rc].r, d, st[rt]);
	d = getDist(st[lc].r, st[rc].l);
	if(d > st[rt].dist) copyNode(st[lc].r, st[rc].l, d, st[rt]);
	d = getDist(st[lc].r, st[rc].r);
	if(d > st[rt].dist) copyNode(st[lc].r, st[rc].r, d, st[rt]);
}

inline void build(int rt, int l, int r){
	if(l == r){
		st[rt].l = l;
		st[rt].r = r;
		st[rt].dist = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	push_up(rt);
}

inline node query(int rt, int l, int r, int x, int y){
	if(l == x && y == r){
		return st[rt];
	}
	int mid = (l + r) >> 1;
	if(y <= mid) return query(lc, l, mid, x, y);
	else if(x > mid) return query(rc, mid + 1, r, x, y);
	else {
		node a = query(lc, l, mid, x, mid);
		node b = query(rc, mid + 1, r, mid + 1, y);
		node ans;
		ans = a.dist > b.dist ? a : b;
		int dist = getDist(a.l, b.l);
		if(dist > ans.dist) copyNode(a.l, b.l, dist, ans);
		dist = getDist(a.l, b.r);
		if(dist > ans.dist) copyNode(a.l, b.r, dist, ans);
		dist = getDist(a.r, b.l);
		if(dist > ans.dist) copyNode(a.r, b.l, dist, ans);
		dist = getDist(a.r, b.r);
		if(dist > ans.dist) copyNode(a.r, b.r, dist, ans);
		return ans;
	}
}

int main(){
	srand(time(NULL));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n; 
	for(int i = 1;i<n;i++){
		int a, b, c;
		cin>>a>>b>>c;
		e[a].pb(mp(b, c));
		e[b].pb(mp(a, c));
	}
	dfs(1, 0, 1, 0);
	build(1, 1, n);
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<query(1, 1, n, l, r).dist<<endl;
	}
}
