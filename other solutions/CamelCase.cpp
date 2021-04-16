#include <iostream>
#include <unordered_set>
#define endl "\n"
using namespace std;
const int N = 2e3 + 10;
const int INF = 1e5 + 10;
int n, dp[N];
unordered_set<string> vis;

inline void solve(){
    for(int i = 1;i<N;i++) dp[i] = INF;
    dp[0] = 0;
    string s;
    cin>>s;
    for(int j = 1;j<=s.size();j++){
        for(int l = 1; l <= s.size(); l++){
            int i = j - l + 1;
            if(i < 1) continue;
            if(vis.count(s.substr(i - 1, l))) dp[j] = min(dp[j], dp[i - 1] + 1);
        }
    }
    cout<<dp[s.size()] - 1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        string s; cin>>s;
        vis.insert(s);
    }
    for(int i = 1;i<=10;i++){
        solve();
    }
    return 0;
}
