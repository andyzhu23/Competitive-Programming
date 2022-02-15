#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

priority_queue<int> heap;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n>>k;
    cin>>s;
    int tot = 0;
    for(int i = 0;i<s.size();++i) {
        if(s[i] == '0') ++tot;
        else {
            heap.push(tot);
            tot = 0;
        }
    }
    heap.push(tot);
    int ans = 0;
    for(int i = 1;i<=k;++i) {
        if(heap.empty()) break;
        ans += heap.top(); heap.pop();
    }
    cout<<ans<<'\n';
    return 0;
}