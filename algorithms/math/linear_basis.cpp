#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
using pli = pair<ll, int>;
int n;
ll d[70];
pli a[N];

bool insert(ll x) {
  for(int i = 62;~i;--i) if((1ll << i) & x){
    if(d[i] == 0) {
      d[i] = x;
      return 1;
    } else x ^= d[i];
  }
  return 0;
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  cin>>n;
  for(int i = 1;i<=n;++i) {
    ll x; int y;
    cin>>x>>y;
    a[i] = {x, y};
  }
  sort(a + 1, a + n + 1, [&](pli a, pli b) {
    return a.second > b.second;
  });
  int ans = 0;
  for(int i = 1;i<=n;++i) {
    auto[x, y] = a[i];
    ans += insert(x) * y;
  }
  cout<<ans<<'\n';
  return 0;
}
