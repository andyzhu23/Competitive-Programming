#include <bits/stdc++.h>

using namespace std;

int n, p;

int main() {
    cin>>n>>p;
    int x = 0;
    vector<pair<int, int> > v;
    for(int i = 1;i<=n;++i) {
        if(i == p) {
            int tmp;
            cin>>x>>tmp;
            continue;
        }
        int a, b;
        cin>>a>>b;
        if(a >= b) v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    for(auto[b, a] : v) {
        if(x >= b) {
            // cout<<a<<' '<<b<<'\n';
            x += a - b;
            ++cnt;
        }
    }
    cout<<x<<'\n'<<cnt<<'\n';
    return 0;
}
