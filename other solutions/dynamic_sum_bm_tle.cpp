#include <bits/stdc++.h>
using namespace std;
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
using ll = long long;
const int N = 3e5 + 10;
int n, q, bsize;
ll ans = 0;
int cnt = 0;

int block[N];
vector<int> a[N], b[N];
vector<int> vala[N], valb[N];
inline void update(int pos, int val) {
    a[pos].pb(cnt);
    vala[pos].pb(val + vala[pos][vala[pos].size() - 1]);
    b[block[pos]].pb(cnt);
    valb[block[pos]].pb(val + valb[block[pos]][valb[block[pos]].size() - 1]);
}

inline int lb(vector<int>& vec, int x) {
    int l = 0, r = vec.size() - 1, ans = 0;
    while(l <= r) { 
        int mid = (l + r) >> 1;
        if(vec[mid] <= x) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

inline ll query(int l, int r, int x) {
    int t = cnt - x;
    int res = 0;
    for(int i = l; i <= min(r, block[l] * bsize); i++) {
        int pos = lb(a[i], t);
        res += vala[i][pos];
    }
    if(block[l] == block[r]) return res;
    for(int i = (block[r] - 1) * bsize + 1; i <= r;i++) {
        int pos = lb(a[i], t);
        res += vala[i][pos];
    }
    for(int i = block[l] + 1; i< block[r];i++) {
        int pos = lb(b[i], t);
        res += valb[i][pos];
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    bsize = sqrt(n);
    for(int i = 0;i<=n + 5;i++) {
        a[i].pb(0);
        b[i].pb(0);
        vala[i].pb(0);
        valb[i].pb(0);
        block[i] = (i - 1) / bsize + 1;
    }
    while(q--) {
        int opt;
        cin>>opt;
        if(opt == 1) {
            ll i, v;
            cin>>i>>v;
            ++cnt;
            i ^= ans;
            v ^= ans;
            update(i, v);
        } else {
            ll l, r, x;
            cin>>l>>r>>x;
            l ^= ans;
            r ^= ans;
            x ^= ans;
            ans = query(l, r, x);
            cout<<ans<<'\n';
        }
    }
    return 0;
}
