#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;

const int N = 2e5 + 10;
int n, q, a[N];
using pii = pair<int, int>;
#define fir first
#define sec second
#define pb push_back
#define all(v) v.begin(), v.end()


ordered_set bst;

bool cmp(pii a, pii b) {
    swap(a.fir, a.sec);
    swap(b.fir, b.sec);
    return a < b;
}

struct Query {
    int first, second, id;
    bool operator<(const Query& other) const {
        return second < other.sec;
    }
};

pii stk[N];
int r = 0, ans[N];
vector<pii> save;
vector<Query> query;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &q);
    for(int i = 1;i<=n;++i) {
        scanf("%d", a + i);
        while(stk[r].fir > a[i]) --r;
        if(stk[r].fir == a[i]) {
            save.pb({stk[r].sec, i});
            stk[r].sec = i;
        } else stk[++r] = {a[i], i};
    }
    for(int i = 1;i<=q;++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        query.pb({l, r, i});
    }
    sort(all(query));
    sort(all(save), cmp);
    int cur = 0;
    for(auto x : query) {
        int l = x.fir, r = x.sec;
        while(cur < save.size() && save[cur].sec <= r) {
            bst.insert(save[cur].fir);
            ++cur;
        }
        ans[x.id] = r - l + 1 - (bst.size() - bst.order_of_key(l));
    }
    for(int i = 1;i<=q;++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
