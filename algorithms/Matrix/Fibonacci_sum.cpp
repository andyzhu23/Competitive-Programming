#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;
int n, MOD;

struct mat{
    ll a[3][3];
    void copy(vector<vector<int>>& b) {
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                a[i][j] = b[i][j];
            }
        }
    }

    mat operator * (mat& other){
        mat ans;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                ans.a[i][j] = 0;
                for(int k = 0;k<3;k++){
                    ans.a[i][j] += a[i][k] % MOD * other.a[k][j] % MOD;
                    ans.a[i][j] %= MOD;
                }
            }
        }
        return ans;
    }

} tmp;

mat fast_pow(mat a, int k){
    if(k == 1) return a;
    tmp = fast_pow(a, k >> 1);
    if(k & 1) return tmp * tmp * a;
    return tmp * tmp;
}

signed main(){
    cin>>n>>MOD;
    vector<vector<int>> m = {{2, 0, 0}, {1, 0, 0}, {1, 0, 0}};
    mat finl;
    finl.copy(m);
    m = {{1, 1, 1}, {0, 1, 1}, {0, 1, 0}};
    mat pow;
    pow.copy(m);

    cout<<(fast_pow(pow, n - 2) * finl).a[0][0]<<endl;
    return 0;
}
