// time complexity O(nlogn + qloglogn)

#include <iostream>
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
int st[N][30], n, m;

// binary search for the last value that 2 to the power of this value is smaller than x
inline int getLog(int x){
    int l = 0, r = 30, ans;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(1 << mid <= x){
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i = 1 ;i<=n;i++) cin>>st[i][0];
    for(int j = 1, len = 2; len <= n; j ++, len = len << 1){
        for(int i = 1;i<=n;i++){
            if(i + len - 1 > n) break;
            // splits the array into 2 much like a segment tree
            st[i][j] = max(st[i][j - 1], st[i + len / 2][j - 1]);
        }
    }
    while(m--){
        int x, y;
        cin>>x>>y;
        int len = y - x + 1;
        int j = getLog(len);
        // st[x][j] covers as much as it can on the left, and st[y - (1 << j) + 1][j] covers as much as it can on the right
        cout << max(st[x][j], st[y - (1 << j) + 1][j]) << endl;
    }
    return 0;
}
