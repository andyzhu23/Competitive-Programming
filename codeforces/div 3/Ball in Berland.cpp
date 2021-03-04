/*
 * count all the times ai and bi appeared, because they will only appear once, therefore all you need to do is just
 * enumerate ai and try to find bi. It is more difficult to find the ones that are valid and without conflict. Therefore
 * it is better if you get the number of ways that are not valid
 * the formula is the total number of pairs left subtract by number of ai and number of bi plus the one that you already have
 */

#include <iostream>
using namespace std;
const int N = 2e5 + 10;
int a, b, k, A[N], B[N], cntA[N], cntB[N];
#define int long long
void solve(){
    cin>>a>>b>>k;
    for(int i = 1;i<=k;i++){
        cin>>A[i];
        cntA[A[i]] ++;
    }
    for(int i = 1;i<=k;i++){
        cin>>B[i];
        cntB[B[i]] ++;
    }
    int ans = 0;
    int cnt = k;
    for(int i = 1;i<=k;i++){
        ans += cnt - cntA[A[i]] - cntB[B[i]] + 1;
        cntA[A[i]]--;
        cntB[B[i]]--;
        cnt--;
    }
    cout<<ans<<endl;

}
int t;
signed main() {
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
