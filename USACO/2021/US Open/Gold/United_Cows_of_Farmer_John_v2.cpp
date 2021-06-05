#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n;
vector<ll> c(N);
vector<int> pre(N);

int lowbit(int x) {return x & (-x);}

void update(int pos, int val){
    for(int i = pos;i<=n;i+=lowbit(i)) c[i] += val;
}

int query(int pos){
    ll ans = 0;
    for(int i = pos;i;i-=lowbit(i)) ans += c[i];
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    ll ans = 0;
    for(int i = 1;i<=n;i++) {
        int x; cin>>x;
        ans += query(i) - query(pre[x]);
        update(i, 1);
        if(pre[x]) update(pre[x], -1);
        pre[x] = i;
    }
    cout<<ans<<endl;
    return 0;
}
