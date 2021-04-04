#include <iostream>
#define endl "\n"
using namespace std;
int n, odd, even;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        int x; cin>>x;
        if(x % 2) odd ++;
        else even ++;
    }
    int ans = 0;
    while(odd > 0 || even > 0){
        if(ans % 2) {
            if (odd > 0) odd--;
            else break;
        }
        else {
            if (even > 0) even--;
            else if (odd >= 2) odd -= 2;
            else if (odd == 1){
                ans --;
                break;
            }
            else break;
        }
        ans ++;
    }

    cout<<ans<<endl;
    return 0;
}
