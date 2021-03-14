#include <iostream>
#include <algorithm>
using namespace std;
const int N = 55;
int t, n;
double a[N];
 
int solve(){
    cin>>n;
    for(int i =1;i<=n;i++) cin>>a[i];
    int ans = 0;
    for(int i =1;i<n;i++){
        if(max(a[i], a[i + 1]) / min(a[i], a[i + 1]) > 2.0){
            int tmp = min(a[i], a[i + 1]) * 2;
            ans ++;
            while(tmp < max(a[i], a[i + 1])){
                tmp *= 2;
                ans ++;
            }
            ans--;
        }
    }
    return ans;
}
 
int main() {
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}
