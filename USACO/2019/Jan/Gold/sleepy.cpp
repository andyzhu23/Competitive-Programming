#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const int N = 1e5 + 10;
int n, a[N], pos;
ordered_set<int> bst;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>a[i];
    bst.insert(a[n]);
    for(int i = n - 1;i;--i) {
        if(a[i] > a[i + 1]) {
            pos = i;
            break;
        }
        bst.insert(a[i]);
    }
    cout<<pos<<'\n';
    for(int i = 1;i<=pos;++i) {
        cout<<pos - i + bst.order_of_key(a[i]);
        cout<<(i == pos ? '\n' : ' ');
        bst.insert(a[i]);
    }
    return 0;
}

