/*
 * Compute permutations by using a frequency array. Use rolling hash to compute the permutations. 
 * I computed the rolling hash twice using two different bases and mod values.
 */

#include <iostream>
#include <unordered_set>
#define endl "\n"
using namespace std;
typedef long long ll;
const int P = 257;
const int MOD = 1e9 + 7;
const int PII = 131;
const int MODII = 100000007;
string n, h;
int needle[29], hay[29], len1, len2;
unordered_set<ll> vis, vis2;

bool isPerm(){
    for(int i = 1;i<=27;i++){
        if(needle[i] != hay[i]) return false;
    }
    return true;
}

int main(){
    cin>>n >>h;
    len1 = n.size();
    len2 = h.size();
    for(int i = 1;i<=len1;i++){
        needle[n[i - 1] - 'a' + 1]++;

    }
    if(len2 < len1) {
        cout<<0<<endl;
        return 0;
    }

    ll power = 1;
    ll power2 = 1;
    for (int i = 1; i < len1; i++) {
        power = (power * P) % MOD;
        power2 = (power2 * PII) % MODII;
    }
    int ans = 0;
    ll ret = 0;
    ll ret2 = 0;
    for(int i = 1; i <=len2;i++){
        hay[h[i - 1] - 'a' + 1] ++;
        // add the last character
        ret = (ret * P + h[i - 1]) % MOD;
        ret2 = (ret2 * PII + h[i - 1]) % MODII;

        if(i < len1) continue;
        if (isPerm() && !(vis.count(ret) && vis2.count(ret2))){
            ans ++;
            vis.insert(ret);
            vis2.insert(ret2);
        }
        hay[h[i - len1] - 'a' + 1] --;
        // delete the first character
        ret = (ret - (power * h[i - len1] % MOD) + MOD) % MOD;
        ret2 = (ret2 - (power2 * h[i - len1] % MODII) + MODII) % MODII;
    }
    cout<<ans<<endl;
    return 0;
}
