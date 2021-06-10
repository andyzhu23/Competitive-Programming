#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int MOD, n;

const ll POW[4][4] = {
        {1, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 1, 0}
};
const ll FINL[4][4] = {
        {3, 0, 0, 0},
        {2, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
};
const ll def[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
};

struct mat{
    ll a[4][4];

    mat(const ll b[4][4]){
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                a[i][j] = b[i][j];
            }
        }
    }

    mat operator * (mat& other) {
        mat ans = mat(def);
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                for(int k = 0;k<4;k++){
                    ans.a[i][j] += a[i][k] * other.a[k][j] % MOD;
                    ans.a[i][j] %= MOD;
                }
            }
        }
        return ans;
    }
};

mat fast_pow(mat a, int k){
    if(k == 1) return a;
    mat tmp = fast_pow(a, k >> 1);
    if(k & 1) return tmp * tmp * a;
    return tmp * tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>MOD;
    if(n == 2) {
        cout<<3 % MOD<<endl;
        return 0;
    } else if(n == 1){
        cout<<1 % MOD<<endl;
        return 0;
    }
    mat pow = mat(POW);
    mat finl = mat(FINL);

    mat ans = fast_pow(pow, n - 2) * finl;
    cout<<((n + 1) % MOD * ans.a[1][0] % MOD + MOD - ans.a[0][0]) % MOD<<endl;
    return 0;
}
