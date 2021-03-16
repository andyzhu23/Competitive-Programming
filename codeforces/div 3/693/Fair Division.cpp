#include <iostream>
using namespace std;


void solve(){
    int n;
    int cnt[3] = {0};
    cin>>n;
    for(int i = 1;i<=n;i++){
        int a; cin>>a;
        cnt[a]++;
    }
    int tot = cnt[1] + cnt[2] * 2;
    if(tot % 2){
        cout<<"NO"<<endl;
        return;
    }
    int sum = tot / 2;
    while(sum >= 2 && cnt[2] > 0){
        sum -= 2;
        cnt[2] --;
    }
    while(sum >=1 && cnt[1] > 0){
        sum -= 1;
        cnt[1] --;
    }
    if(sum == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
