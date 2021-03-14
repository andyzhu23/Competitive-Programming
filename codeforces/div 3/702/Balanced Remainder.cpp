#include <iostream>
using namespace std;
const int N = 3e4 + 10;
int n, a[N];
int solve(){
    cin>>n;
    int c0 = 0, c1 = 0, c2 = 0;
    for(int i =1;i<=n;i++){
        cin>>a[i];
        if(a[i] %3 == 0) c0 ++;
        else if(a[i] % 3 == 1) c1 ++;
        else c2 ++;
    }
    int ans = 0;
    while(c0 != c1 || c1 != c2){
        if(c0 > c1){
            c0--;
            c1 ++;
            ans ++;
        }
        if(c1 > c2){
            c1 --;
            c2 ++;
            ans++;
        }
        if(c2 > c0){
            c2--;
            c0++;
            ans++;
        }
    }
    return ans;
}
 
int t;
int main() {
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}
