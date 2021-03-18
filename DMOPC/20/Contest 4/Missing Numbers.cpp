#include <iostream>
#define int long long
using namespace std;
int n, s;
void solve(){
    cin>>n>>s;
    int sum = (1 + n) * n / 2;
    int taken = sum - s;
    int smallest = taken - n;
    int biggest = taken - 1;
    if(smallest >= n || (smallest<=0 && biggest > n)){
        cout<<0<<endl;
        return;
    }
    //cout<<smallest<<endl;
    int ans;
    if(smallest > 0) ans = (n - smallest + 1) / 2;
    else if(biggest < n) ans =(biggest) / 2;
    else{
        smallest ++;
        ans = (n - smallest) / 2;
    }
    if(ans < 0) ans = 0;
    cout<<ans<<endl;
}

signed main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
