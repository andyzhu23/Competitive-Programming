#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;
typedef long long ll;
const int N = 30;
int n, a[N], b[N];
bool cmp(int x, int y){
    return x > y;
}

int binarySearch(int x){
    int l = 1, r = n, ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(b[mid] >= x){
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++) cin>>b[i];
    sort(b + 1, b + n + 1, cmp);
    sort(a + 1, a + n + 1, cmp);
    ll ans = 1;
    for(int i = 1;i<=n;i++){
        ans *= binarySearch(a[i]) - i + 1;
    }
    cout<<ans<<endl;
    return 0;
}
