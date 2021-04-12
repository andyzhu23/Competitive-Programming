#include <iostream>
#define int long long
#define endl "\n"
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
int n, w, len = 0;
ll dp[N], sum1[N], sum2[N];

int binarySearch(){
    int l = 0, r = len - 1, ans = len;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(sum1[len] - sum1[mid] <= w){
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>w;
    while(n--){
        char opt;
        cin>>opt;
        ll p, c;
        if(opt == 'D'){
            len--;
            continue;
        }
        cin>>p>>c;
        len++;
        sum1[len] = sum1[len - 1] + p;
        sum2[len] = sum2[len - 1] + c;
        int k = binarySearch();
        dp[len] = max(dp[len - 1], sum2[len] - sum2[k]);
        cout<<dp[len]<<endl;
    }
    return 0;
}
