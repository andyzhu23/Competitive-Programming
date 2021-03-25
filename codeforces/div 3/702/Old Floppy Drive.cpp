/*
 * first determine how many full spins does it require, then you can binarySearch the left overs. First think
 * removing the ones that are smaller, but an easier approach is to just overwrite the ones that are smaller with the
 * greatest value that appeared before.
 */

#include <iostream>
#include <memory.h>
#define endl "\n"
#define int long long
using namespace std;
const int N = 2e6 + 10;
int n, m, a[N], prefix[N];
int Max, Min = 10000000, cnt, remain, increase[N];

inline int binarySearch(int x){
    int l = 0, r = n, mid, ans;
    while(l <= r){
        mid = (l + r) >> 1;
        if(increase[mid] >= x){
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

inline int solve2(int x){
    if(prefix[n] == 0 || (prefix[n] > 0 && x < 0) || (prefix[n] < 0 && x > 0)) cnt = 0;
    else cnt = (x - Max) / prefix[n];
    cnt = max((int) (0), cnt);
    if(prefix[n] == 0 || (prefix[n] > 0 && x < 0) || (prefix[n] < 0 && x > 0)) remain = x;
    else {
        remain = x - cnt * prefix[n];
        while (remain > Max) {
            remain -= prefix[n];
            cnt++;
        }
    }
    if(prefix[n] <= 0 && x > Max) return -1;
    return cnt * n + binarySearch(remain) - 1;
}

inline void solve(){
    memset(prefix, 0, N);
    memset(increase, 0, N);
    Max = -10000000, Min = -Max;
    scanf("%lld %lld", &n, &m);
    for(int i = 1;i<=n;i++){
        scanf("%lld", &a[i]);
        prefix[i] = prefix[i - 1] + a[i];
        Max = max(prefix[i], Max);
        Min = min(prefix[i], Min);
        increase[i] = Max;
    }
    while(m--){
        int x; scanf("%lld", &x);
        printf("%lld ", solve2(x));
    }
    printf("\n");
}

signed main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    int t; scanf("%lld", &t);
    while(t--){
        solve();
    }
    return 0;
}
