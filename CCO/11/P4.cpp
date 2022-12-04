#include <bits/stdc++.h>
using namespace std;

int n;
multiset<int> bst;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    int x; cin>>x;
    bst.insert(x);
    bst.insert(x);
    for(int i = 2;i<=n;++i) {
        int x; cin>>x;
        auto it = bst.upper_bound(x);
        if(it == bst.begin()) {
            puts("NO");
            return 0;
        }
        it = prev(it);
        bst.erase(it);
        bst.insert(x);
        bst.insert(x);
    }
    puts("YES");
    return 0;
}
