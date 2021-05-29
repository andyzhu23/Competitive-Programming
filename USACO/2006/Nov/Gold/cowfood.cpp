#include <iostream>
#include <vector>
#define endl "\n"
#define pb push_back
using namespace std;
const int N = 15;
const int MOD = 1e8;
vector<int> land(N); // store what land is grass
vector<int> mask; // store all possible permutations
int m, n, dp[N][400];

// whether this permutation fit with the constraints of the land
inline bool ok(int& a, int& b){
    if((a & b) == a) return true;
    return false;
}

int main(){
    cin>>m>>n;
    for(int i = 0;i<(1 << n);i++){
        if(i & (i << 1) || i & (i >> 1)) continue;
        mask.pb(i);
    }
    int sz = mask.size();
    for(int i = 1;i<=m;i++){
        for(int j = 0;j<n;j++){
            int x; cin>>x;
            land[i] += x << j;
        }
    }
    for(int i = 0;i<sz;i++)
        if(ok(mask[i], land[1])) dp[1][i] = 1;
    for(int i = 2;i<=m;i++){
        for(int j = 0;j<sz;j++){
            if(!ok(mask[j], land[i])) continue;
            for(int k = 0;k<sz;k++)
                if(!(mask[j] & mask[k])) 
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        }
    }
    int ans = 0;
    for(int i = 0;i<sz;i++){
        ans = (ans + dp[m][i]) % MOD;
    }
    cout<<ans<<endl;
    return 0;
}
