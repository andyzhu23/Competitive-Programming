/*
 * Author: Andy Zhu
 * @date    2021-08-24 07:32:32
 * @version 1.0.0
 */

//include
#include <bits/stdc++.h>
using namespace std;

#define OJ ONLINE_JUDGE
using ll = long long;
int MOD = 1e9 + 7;
template <typename T> inline T lowbit(T x){return x & (- x);}

const int N = 4e6 + 10;
int n, sum[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>MOD;
    sum[n] = 1;

    for(int i = n - 1;i>0;i--) {
        int cur = 0;
        cur += sum[i + 1];
        for(int j = 2; j * i <= n;j++) {
            cur += (sum[i * j] - sum[min(i * j + j, n + 1)] + MOD) % MOD;
            cur %= MOD;
        }
        sum[i] = (sum[i + 1] + cur) % MOD;
    }
    cout<<(sum[1] - sum[2] + MOD) % MOD<<'\n';
}


/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/