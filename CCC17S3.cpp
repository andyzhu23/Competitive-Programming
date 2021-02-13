#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e3+10;

int f[N],n,a;

bool isOk(int i, int j){
    return i-j<=2000;
}

int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a;
        f[a]++;
    }
    int ans = 0;
    int tim = 0;
    for(double i = 2;i<=4000;i++){
        int res = 0;
        for(double j = 1;j<=i/2;j++){
            if(isOk(i,j)){
                if(j==i/2){
                    res +=f[(int)j]/2;
                } else res+= min(f[(int)j],f[(int)(i-j)]);
            }
        }
        if(res>ans){
            ans = res;
            tim = 1;
        } else if(res == ans){
            tim++;
        }
    }
    cout<<ans<<" "<<tim;
    return 0;
}
