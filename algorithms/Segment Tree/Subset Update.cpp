#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll sum[N << 2], lazy[N << 2];
int n, q;
ll a[N];

void push_up(ll rt){
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void push_down(ll rt, ll l, ll r, ll mid){
  sum[rt << 1] += (mid - l + 1) * lazy[rt];
  sum[rt << 1 | 1] += (r - mid) * lazy[rt];
  lazy[rt << 1] += lazy[rt];
  lazy[rt << 1 | 1] += lazy[rt];
  lazy[rt] = 0;
}

void build(ll rt, ll l, ll r){
  if(l == r){
    sum[rt] = a[l];
    return;
  }
  ll mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  push_up(rt);
}

void update(ll rt, ll l, ll r, ll x, ll y, ll val){
  if(l == x && y == r){
    lazy[rt] += val;
    sum[rt] += (r - l + 1) * val;
    return;
  }
  ll mid = (l + r) >> 1;
  push_down(rt, l, r, mid);
  if(y <= mid) update(rt << 1, l, mid, x, y, val);
  else if(x > mid) update(rt << 1 | 1, mid + 1, r , x, y, val);
  else update(rt << 1, l, mid, x, mid, val), update(rt << 1 | 1, mid + 1, r, mid + 1, y, val);
  push_up(rt);
}

ll query(ll rt, ll l, ll r, ll x, ll y){
  if(l == x && y == r){
    return sum[rt];
  }
  ll mid = (l + r ) >> 1;
  push_down(rt, l, r, mid);
  if(y <= mid) return query(rt << 1, l, mid, x, y);
  else if( x > mid) return query(rt << 1 | 1, mid + 1, r, x, y);
  else return query(rt << 1, l, mid, x, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, y);
}

int main(){
  scanf("%d %d", &n, &q);
  for(int i = 1;i<=n;i++){
    ll x; scanf("%lld", &x ); 
    a[i] = x;
  }
  build(1, 1, n);
  while(q--){
    char c;
    ll x, y;
    cin>>c;
    scanf("%lld %lld", &x, &y);
    if(c == 'C'){
      ll val;
      scanf("%lld", &val);
      update(1, 1, n, x, y, val);
    } else {
      printf("%lld\n", query(1, 1, n, x, y));
    }
  }
  return 0;
}
