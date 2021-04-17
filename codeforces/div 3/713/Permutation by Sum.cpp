#include <iostream>
#include <unordered_set>
#include <memory.h>
#define endl "\n"
using namespace std;
const int N = 510;
int n, l, r, s;
int a[N];
unordered_set<int> vis;

inline void solve(){
    vis.clear();
    memset(a, 0, sizeof(a));
    cin >> n >> l >> r >> s;
    int len = r - l + 1;
    int sum = 0;
    int cnt = 0;
    for(int i = l;i<=r;i++){
        a[i] = ++cnt;
        vis.insert(cnt);
        sum += cnt;
    }
    if(sum > s || (n * (n + 1) >> 1) - ((n - len) * (n - len + 1) >> 1) < s) {
        cout<<-1<<endl;
        return;
    }
    int pos = r;
    int Max = n;
    while(sum < s){
        if(a[pos] == Max){
            Max --;
            pos --;
            continue;
        }
        vis.erase(a[pos]);
        a[pos] ++;
        sum++;
        vis.insert(a[pos]);
    }
    for(int i = 1;i<=n;i++){
        if(a[i]) continue;
        if(vis.count(i)){
            int j = 1;
            while(vis.count(j)) ++j;
            a[i] = j;
            vis.insert(j);
        } else {
            a[i] = i;
            vis.insert(i);
        }
    }
    for(int i =1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
