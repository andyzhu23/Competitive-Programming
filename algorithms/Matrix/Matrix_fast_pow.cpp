#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 12;
const int MOD = 4399;
int n, k;

struct mat{
    int a[N][N];
    mat operator *(mat& other){
        mat ans;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                for(int k = 1;k<=n;k++){
                    ans.a[i][j] = a[i][k] * other.a[k][j];
                }
            }
        }
        return ans;
    }
} a;

mat fast_pow(mat a, int k){
    if(k == 1) return a;
    mat tmp = fast_pow(a, k >> 1);
    if(k & 1) {
        return tmp * tmp * a;
    } else {
        return tmp * tmp;
    }
}

int main(){
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>a.a[i][j];
        }
    }
    mat res = fast_pow(a, k);
    int ans = 0;
    for(int i = 1;i<=n;i++){
        ans += res.a[i][i];
    }
    cout<<ans<<endl;
    return 0;
}
