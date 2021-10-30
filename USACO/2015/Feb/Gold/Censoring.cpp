#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define pb push_back
string a;
const int N = 1e5 + 10;
ull stk[N];
char ans[N];
unordered_map<int, unordered_set<ull> > keys;
unordered_set<int> siz;
int n;
ull p[N], base = 131;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else 
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>n;
    p[0] = 1;
    for(int i = 1;i<N;++i) p[i] = base * p[i - 1];
    for(int i = 1;i<=n;++i) {
        string x; cin>>x;
        int sz = x.size();
        ull key = 0;
        for(char c : x) key = key * base + c;
        keys[sz].insert(key);
        siz.insert(sz);
    }
    int tot = 0;
    for(int i = 0;i<a.size();++i) {
        ans[++tot] = a[i];
        stk[tot] = stk[tot - 1] * base + a[i];
        for(int len : siz) {
            if(i - len + 1 < 0) continue;
            if(keys[len].count(stk[tot] - stk[tot - len] * p[len])) {
                tot -= len;
            }
        }
    }
    for(int i = 1;i<=tot;++i) putchar(ans[i]);
    putchar('\n');
    return 0;
}
