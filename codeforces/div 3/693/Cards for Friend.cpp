#include <iostream>
#include <queue>
using namespace std;
struct p{
    int f, s, time;
    p(int F, int S, int T){
        f = F, s = S, time = T;
    }
};
int w, h, n;
void solve(){
    queue<p> q;
    cin>>w>>h>>n;
    q.push(p(w, h,1));
    int ans = 0;
    while(!q.empty()){
        p cur = q.front(); q.pop();
        if(cur.f %2 == 0){
            cur.f /= 2;
            cur.time*= 2;
            q.push(cur);
        } else if( cur.s %2 == 0){
            cur.s /=2;
            cur.time *=2;
            q.push(cur);
        } else {
            ans += cur.time;
        }
    }
    if(ans >= n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
