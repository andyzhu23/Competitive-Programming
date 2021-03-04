#include <iostream>
using namespace std;
const int N =1e4+10;

int n,a[N],dp[N];
int len;

int binarySearch(int x){
    int l = 1, r = len, mid;
    int ans;
    while(l<=r){
        mid = (l + r)/2;
        if(dp[mid] < x) l = mid + 1;
        else {
            r = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    len = 1;
    dp[1] = a[1];
    for(int i = 2;i<=n;i++){
        if(a[i]>dp[len]) dp[++len] = a[i];
        else{
            int k = binarySearch(a[i]);
            dp[k] = a[i];
        }
    }
    int ans;
    for(int i = 1;i<=n;i++){
        if(dp[i]>0) ans = i;
    }
    cout<<ans;
    return 0;
}
