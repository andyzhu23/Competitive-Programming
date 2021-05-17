#include <iostream>
#include <unordered_map>
#include <memory.h>
using namespace std;

const int N = 2e3 + 10;
int vis[N], n, q, a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i =1 ;i<=n;i++){
        cin>>a[i];
    }
    int ans = 0;
    while(q--){
        int l, r;
        cin>>l>>r;
        l ^= ans;
        r ^= ans;
        memset(vis, 0, sizeof(vis));
        for(int i = l;i<=r;i++){
            vis[a[i]] ++;
        }
        // get left most endpoint
        int lft = l;
        while(lft > 1){
            if(vis[a[lft - 1]]) break;
            vis[a[--lft]]++;
        }
        int rgt = r;
        ans = r - lft + 1;
        while(rgt < n){
            if(!vis[a[rgt + 1]]) {
                rgt++;
                vis[a[rgt]]++;
                ans = max(ans, rgt - lft + 1);
            } else if(lft < l){
                lft ++;
                vis[a[lft - 1]] --;
            } else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
