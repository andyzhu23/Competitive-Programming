#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = unsigned long long;
int MOD = 1e9 + 7;
struct Long {
    string a;
    void update(){
        int i = a.size() - 1;
        int cnt = 2;
        if(a[i] - '0' >= cnt) {
            a[i] -= 2;
            return;
        }
        while(a[i] - '0' < cnt) {
            a[i] = a[i] + 10 - cnt;
            i--;
            cnt = 1;
        }
        a[i] -=cnt;
    }
} n;

struct mat{
    ll a[3][3];
    mat operator * (mat& other){
        mat ans;
        for(int i = 1;i<=2;i++){
            for(int j = 1;j<=2;j++){
                ans.a[i][j] = 0;
                for(int k = 1;k<=2;k++){
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
    bool flag = k & 1;
    tmp = fast_pow(a, k >> 1);
    if(flag) return tmp * tmp * a;
    else return tmp * tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n.a;
    if(n.a == "1" || n.a == "2"){
        cout<<1<<endl;
        return 0;
    }
    n.update();
    string& s = n.a;
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
    for(int i = s.size() - 1;i>=0;i--){
        int cnt = s[i] - '0';
        for(int i = 0;i<cnt;i++){
            b = b * matr;
        }
        matr = fast_pow(matr, 10);
    }
    cout<<(b.a[1][1] + b.a[1][2]) % MOD<<endl;
    return 0;
}
