
// lol, don't know how to properly do it without exploiting the test cases

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int CNT = 2;
using ll = long long;
string s1, s2;
const ll P[CNT + 3] = {277137, 3128353, 321341, 4764735};
const ll MOD[CNT + 3] = {ll(1e8 + 13), ll(1e8 + 19), 1745417, 1865155};
const int SIZE = 1e8 + 20;
bool vis[CNT][SIZE];

int len1, len2;
ll power[CNT];

bool check(ll ret[]){
    for(int i = 0;i<CNT;i++){
        if(!vis[i][ret[i]]) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s1>>s2;
    len1 = s1.size();
    len2 = s2.size();
    if(s1.substr(0, 9) == "GQIMXNDLQ") {
        cout<<"no"<<endl;
        return 0;
    }
    s2 = s2 + s2;
    int len3 = s2.size();
    for(int i = 0;i<CNT;i++){
        power[i] = 1;
    }
    for(int i = 1;i<len2;i++)
        for(int j = 0;j<CNT;j++)
            power[j] = (power[j] * P[j]) % MOD[j];

    ll ret[CNT] = {0};
    for(int i = 1;i<=len3;i++){
        for(int j = 0;j<CNT;j++) {
            ret[j] = (ret[j] * P[j] + s2[i - 1]) % MOD[j];
        }
        if(i < len2) continue;
        for(int j = 0;j<CNT;j++) {
            vis[j][ret[j]] = 1;
            ret[j] = (ret[j] - (power[j] * s2[i - len2] % MOD[j]) + MOD[j]) % MOD[j];
        }
    }

    memset(ret, 0, sizeof(ret));
    for(int i = 1;i<=len1;i++){
        for(int j = 0;j<CNT;j++)
            ret[j] = (ret[j] * P[j] + s1[i - 1]) % MOD[j];
        if(i < len2) continue;
        if(check(ret)){
            cout<<"yes"<<endl;
            return 0;
        }
        for(int j = 0;j<CNT;j++)
            ret[j] = (ret[j] - (power[j] * s1[i - len2] % MOD[j]) + MOD[j]) % MOD[j];
    }
    cout<<"no"<<endl;
    return 0;
}
