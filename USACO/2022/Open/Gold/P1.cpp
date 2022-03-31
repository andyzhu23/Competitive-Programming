#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

struct node {
    int q, t, x, n;
    bool operator<(const node& other) const {
        return t + x > other.t + other.x;
    }
};
vector<node> a;
map<int, int, greater<int> > mp;

int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    for(int i = 1;i<=n;++i) {
        int q, t, x, n;
        cin>>q>>t>>x>>n;
        a.pb({q, t, x, n});
    }
    sort(a.begin(), a.end(), [&](node& a, node& b) {
        if(a.x - a.t == b.x - b.t) return a.q > b.q;
        return a.x - a.t < b.x - b.t;
    });
    int ans = 0;
    for(node& x : a) {
        if(x.q == 2) mp[x.x + x.t] += x.n;
        else {
            while(1) {
                auto it = mp.upper_bound(x.x + x.t);
                if(it == mp.begin()) break;
                it = prev(it);
                if(x.n <= (*it).s) {
                    (*it).s -= x.n;
                    ans += x.n;
                    break;
                } else {
                    x.n -= (*it).s;
                    ans += (*it).s;
                    if(it == mp.begin()) {
                        mp.erase(it);
                        break;
                    }
                    mp.erase(it);
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}