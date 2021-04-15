#include <iostream>
#include <memory.h>
#define endl "\n"
using namespace std;
const int N = 1e7 + 10;
int res[N], ans[N];

inline void cal(){
    int cnt = 0;
    while(++cnt < N){
        for(int i = cnt;i<N;i+=cnt){
            res[i] += cnt;
        }
    }
    for(int i = 1;i<N;i++){
        if(res[i] >= N) continue;
        if(ans[res[i]] == -1) ans[res[i]] = i;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(ans, -1, sizeof(ans));
    cal();
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}
