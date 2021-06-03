#include <bits/stdc++.h>
#define endl "\n"
#define ALL(v) v.begin(), v.end()
using namespace std;
const int N = 1e3 + 10;

int h, k;
vector<int> a(2 * N);

bool ok(int x){
    int len = x * 2;
    vector<int> dist(2 * N);
    for(int i = 1;i<=h;i++){
        dist[i] = upper_bound(ALL(a), a[i] + len) - a.begin() - 1;
    }
    for(int i = 1;i<=h;i++){
        dist[i + h] = dist[i] + h;
    }
    for(int i = 1;i<=h;i++){
        int cnt = 0;
        for(int j = i;j < i + h; j = dist[j] + 1) {
            cnt++;
        }
        if(cnt <= k) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>h;
    for(int i = 1;i<=h;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=h;i++){
        a[i + h] = a[i] + 1e6;
    }
    sort(a.begin() + 1, a.begin() + 1 + 2 * h);
    for(int i = 2 * h + 1; i<a.size();i++) a[i] = 1e9;
    cin>>k;
    int l = 0, r = 1e6, ans;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout<<ans<<endl;
    return 0;
}
