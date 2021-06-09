#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = unsigned long long;
ll MOD = 1e9 + 7;
ll n;

struct mat{
    ll a[3][3];
    mat operator * (mat& other){
        mat ans;
        memset(ans.a, 0, sizeof(ans.a));
        for(int i = 1;i<=2;i++){
            for(int j = 1;j<=2;j++){
                for(int k = 1;k<=2;k++){
                    ans.a[i][j] += a[i][k] % MOD * other.a[k][j] % MOD;
                    ans.a[i][j] %= MOD;
                }
            }
        }
        return ans;
    }
};

mat fast_pow(mat a, ll k){
    if(k == 1) return a;
    mat tmp = fast_pow(a, k >> 1);
    if(k & 1) return tmp * tmp * a;
    else return tmp * tmp;
}

int main(){
    cin>>n;
    mat matr;
    matr.a[1][1] = 1;
    matr.a[1][2] = 1;
    matr.a[2][1] = 1;
    matr.a[2][2] = 0;
    mat b;
    b.a[1][1] = 1;
    b.a[1][2] = 0;
    b.a[2][1] = 1;
    b.a[2][2] = 0;
    mat ans = fast_pow(matr, n - 2) * b;
    cout<<ans.a[1][1]<<endl;

    return 0;
}
