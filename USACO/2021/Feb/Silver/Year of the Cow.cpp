/* I am an idiot in that I didn't define N and L big enough to pass the last test case
 * anyways read the poem if you want more information
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#define int long long
using namespace std;
const int N = 655360;
const int L = 547200;
int n, k, a[N], b[L];

unordered_set<int> Map;
priority_queue<int> pq;

bool cmp(int a, int b){
    return a > b;
}

signed main() {
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    //compress the array into 12 year period
    for(int i = 1;i<=n;i++){
        Map.insert(a[i] / 12 + 1);
    }
    int len = 0;
    for (auto it = Map.begin(); it != Map.end(); it++) {
        b[++len] = *it;
    }

    //sort array from greatest to smallest
    sort(b + 1, b + len + 1, cmp);
    int ans = b[1] * 12;
    for(int i = 1;i<=len;i++){
        pq.push(b[i] - b[i + 1]);
    }
    for(int i = 1;i<=k - 1;i++){ // the first portal is already used so it is k - 1 right here
        if(pq.empty()) break;
        ans -= pq.top() * 12;pq.pop();
        ans += 12;
    }
    cout<<ans<<endl;

    return 0;
}
