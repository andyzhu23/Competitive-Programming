#include <iostream>
#include <unordered_map>
#include <algorithm>
#define push_up(rt) cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
#define endl "\n"
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, cnt[N << 2], a[N], b[N];
unordered_map<int, int> Map;

inline int query(int rt, int l, int r, int x, int y){
    if(l == x && y == r){
        return cnt[rt];
    }
    int mid = (l + r) >> 1;
    if(y <= mid) return query(rt << 1, l, mid, x, y);
    else if(x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
    else return query(rt << 1, l, mid, x, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, y);
}

inline void update(int rt, int l, int r, int pos, int val){
    if(l == r){
        cnt[rt] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    push_up(rt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    int len = 0;
    for(int i = 1;i<=n;i++){
        if(Map[a[i]] == 0) Map[a[i]] = ++len;
    }
    for(int i = 1;i<=n;i++){
        int x = Map[b[i]];
        ans += query(1, 1, n + 1, x + 1, n + 1);
        update(1, 1, n, x, 1);
    }
    cout<<ans<<endl;
    return 0;
}
