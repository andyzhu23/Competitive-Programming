#include <iostream>
#include <memory.h>
#define endl "\n"
using namespace std;
const int N = 3e5 + 10;
int n, a[N], prefix[N], suffix[N];
int solve(){
    cin>>n;
    memset(a, 0, sizeof(a));
    memset(prefix, 0, sizeof(prefix));
    memset(suffix, 0, sizeof(suffix));
    for(int i = 1;i<=n;i++) cin>>a[i];
    int ans = 2;
    if(n == 2) return 2;
    if(n == 3) return 3;
    prefix[1] = 1;
    prefix[2] = 2;
    for(int i = 3;i<=n;i++){
        if(a[i] - a[i - 1] == a[i - 1] - a[i - 2]) prefix[i] = prefix[i - 1] + 1;
        else prefix[i] = 2;
    }
    suffix[n] = 1;
    suffix[n - 1] = 2;
    for(int i = n - 2;i>=1;i--){
        if(a[i] - a[i + 1] == a[i + 1] - a[i + 2]) suffix[i] = suffix[i + 1] + 1;
        else suffix[i] = 2;
    }
    for(int i = 1;i<=n;i++){
        ans = min(n, max(ans, max(prefix[i - 1] + 1, suffix[i + 1] + 1)));
        if((i > 2 && i <= n - 2) && a[i - 1] - a[i - 2] == a[i + 2] - a[i + 1]
        && a[i + 1] - a[i - 1] == 2 * (a[i - 1] - a[i - 2]))
            ans = max(ans, prefix[i - 1] + suffix[i + 1] + 1);
        if(i >= 2 && i <= n - 2 && a[i + 1] - a[i - 1] == 2 * (a[i + 2] - a[i + 1])){
            ans = max(ans, suffix[i + 1] + 2);
        }
        if(i >= 3 && i < n && a[i + 1] - a[i - 1] == 2 * (a[i - 1] - a[i - 2])){
            ans = max(ans, prefix[i - 1] + 2);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    for(int i = 1;i<=t;i++){
        cout<<"Case #" << i << ": "<< solve() << endl;
    }
    return 0;
}
