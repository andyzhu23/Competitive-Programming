#include <bits/stdc++.h>
using namespace std;

const int N = 300;
int n, b, f[N];

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin>>n>>b;
    for(int i = 1;i<=n;++i) cin>>f[i];
    int cur = 1;
    for(int i = 1;i<=b;++i) {
        int s, d;
        cin>>s>>d;
        int last = cur;
        while(f[cur] > s) --cur;
        while(cur < n) {
            bool flag = 0;
            int nxt = cur;
            for(int k = 1;k<=d;++k) {
                if(f[cur + k] <= s) {
                    nxt = cur + k;
                    flag = 1;
                }
            }
            cur = nxt;
            if(!flag) break;
        }
        if(last > cur) cur = last;
        if(cur >= n) {
            cout<<(i - 1)<<'\n';
            return 0;
        }
    }
    return 0;
}
