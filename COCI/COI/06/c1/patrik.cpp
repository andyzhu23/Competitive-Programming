#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fir first
#define sec second

using ll = long long;
using pii = pair<int, int>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    ll ans = 0;
    stack<pii> stk;
    for(int i = 1;i<=n;i++) {
        int x; cin>>x;
        while(!stk.empty() && stk.top().fir < x) {
            ans += stk.top().sec;
            stk.pop();
        }
        int cnt = 1;
        if(!stk.empty() && stk.top().fir == x) {
            cnt += stk.top().sec;
            ans += stk.top().sec;
            stk.pop();
        }
        ans += !stk.empty();
        stk.push(mp(x, cnt));
    }
    cout<<ans<<"\n";
    return 0;
}
