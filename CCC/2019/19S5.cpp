#include <bits/stdc++.h>
using namespace std;

template <typename T> using vec = vector<T>;
using ll = long long;
// best number to use for sub triangle is 2/3 n
#define get(k) k == 2 ? 1 : (2 * k - 1) / 3 + 1

const int N = 4e3 + 10;
int a[N][N];
int n;

void dfs(int k) {
    if(k == 1) return;
    // greedy here, want to triangles to be the smallest possible
    // so it is the smallest number bigger than 2/3 n. Only 2 don't work
    int nxt = get(k);
    dfs(nxt);
    // for every triangle, calculate max of sub triangles at the two bottom vertices as well as 
    // the top of the current triangle
    for(int i = 1;i<=n - k + 1;i++) 
        for(int j = 1;j<=i;j++) 
            a[i][j] = max(a[i][j], max(a[i + k - nxt][j], a[i + k - nxt][j + k - nxt]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++) 
        for(int j = 1;j<=i;j++) 
            cin>>a[i][j];
    dfs(k);
    ll ans = 0;
    for(int i = 1;i<=n - k + 1;i++) {
        for(int j = 1;j<=i;j++) {
            ans += a[i][j];
        }
    }
    cout<<ans<<'\n';
    return 0;
}