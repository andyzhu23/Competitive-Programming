#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e2 + 10;
 
struct pos{
    int pos, value, l, r;
};
 
int n, ans[N];
pos a[N];
 
void dfs(int dep, pos fa){
    pos l, r;
    l.value = r.value = -1;
    for(int i = fa.l + 1;i<fa.pos;i++){
        if(l.value < a[i].value){
            l.pos = i;
            l.value = a[i].value;
        }
    }
    if(l.value != -1){
        l.l = fa.l;
        l.r = fa.pos;
        ans[l.pos] = dep;
        dfs(dep + 1, l);
    }
    for(int i = fa.pos + 1;i < fa.r; i++){
        if(r.value < a[i].value){
            r.pos = i;
            r.value = a[i].value;
        }
    }
    if(r.value != -1){
        r.l = fa.pos;
        r.r = fa.r;
        ans[r.pos] = dep;
        dfs(dep + 1, r);
    }
}
 
void solve(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].value;
        a[i].pos = i;
    }
    pos start;
    start.pos = n + 1;
    start.r = n + 1;
    start.l = 0;
 
    dfs(0,start);
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
 
int t;
int main() {
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
