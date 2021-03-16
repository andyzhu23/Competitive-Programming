#include <iostream>
using namespace std;
const int N = 2e5 + 10;
int n;
void solve(){
    int a[N] = {0};
    int suffix[N] = {0};
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i = n;i >=1;i--){
        if(i + a[i] > n) suffix[i] = a[i];
        else suffix[i] = a[i] + suffix[i + a[i]];
        ans = max(ans, suffix[i]);
    }
    cout<<ans<<endl;

}


int main() {
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
