/*
 * for this question there is no challenge in the actual algorithm, but how to obtain the permutation.
 * I learned that this method of calculating the permutation comes from the little fermat theorem. where
 * if a and p are relatively prime then pow(a , p - 1) % p = 1. Because we know the reversed value of a and
 * a multiply together mod any number is 1. Therefore, we can calculate the reversed value of a since
 * if pow(a, p - 1) % p = 1 then a * pow(a, p - 2) % p = 1 then pow(a, p - 2) is the reverse value of a.
 * Therefore, we can obtain that value using fast_pow and we can use the reversed value to multiple which
 * statisfies the rules of modulos
 */

#include <iostream>
#include <algorithm>
#include <string.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
const int MOD = 1e9 + 7;
int n, k, a[N], cnt[N];
bool cmp(int x, int y){
    return y < x;
}

ll fast_pow(int x, int y){
    if(y == 0) return 1;
    if(y == 1) return x;
    if(y % 2 == 0){
        ll tmp = fast_pow(x, y / 2);
        return tmp % MOD * tmp % MOD;
    } else {
        ll tmp = fast_pow(x, y / 2);
        return tmp % MOD * tmp % MOD * x % MOD;
    }
}

ll fac(int x){
    int ans = 1;
    for(int i = 2;i<=x;i++){
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

int getPerm(ll v, ll u){
    if(u == v) return 1;
    ll fu = fac(u);
    ll fv = fac(v);
    ll fvu = fac(v - u);
    return fv * fast_pow(fu, MOD - 2) % MOD * fast_pow(fvu, MOD - 2) % MOD;
}

void solve(){
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(a + 1, a + n + 1, cmp);
    int u = 0, v;
    v = cnt[a[k]];
    for(int i = k;i > 0; i --){
        if(a[i] == a[k]) u++;
        else break;
    }
    cout<<getPerm(v, u)<<endl;
    memset(cnt, 0, N);
}

signed main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
