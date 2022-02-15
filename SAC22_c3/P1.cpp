#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int a, b, c;
    cin>>a>>b>>c;
    for(int i =1;i<=c;++i) {
        a -= b;
        cout<<a<<'\n';
    }
    return 0;
}