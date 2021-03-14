/*
 * for this question, a simple brut force that I did earlier is using Dynamic Programming to 
 * calculate the answer. However, we can go over the required limit so using the Dynamic Programming method
 * will end up TLE. 
 * 
 * The right way to do this problem is when we look at the importance of a file. Why did the problem maker only 
 * give us 1 and 2? Well, if we continue to think this way then it will be clear that we can store them as just two arrays
 * important and regular. We enumerate through all the regular files(first sort them from biggest to smallest),
 * we can use binary search to quickly figure out how many more apps we need to delete in order to free the storage.
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second
#define pb push_back
#define int long long
using namespace std;
typedef pair<int, int> p;
typedef vector<int> vi;
const int N = 2e5 + 10;
const int INF = 2e9 + 10;
int n, m, l1, l2, sum1[N], sum2[N];
p a[N];


bool cmp(int a, int b){
    return b < a;
}

int binarySearch(int x){
    int l = 0, r = l2 + 1, mid, ans;
    while(l <= r){
        mid = (l + r) / 2;
        if(sum2[mid] >= x){
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

void solve(){
    cin>>n>>m;
    vi reg;
    vi imp;
    for(int i = 1;i<=n;i++){
        cin>>a[i].f;
    }
    for(int i = 1;i<=n;i++){
        cin>>a[i].s;
        if(a[i].s == 1){
            reg.pb(a[i].f);
        } else {
            imp.pb(a[i].f);
        }
    }
    l1 = reg.size();
    l2 = imp.size();
    sort(reg.begin(), reg.end(),cmp);
    sort(imp.begin(), imp.end(),cmp);
    for(int i = 1;i<=l1;i++){
        sum1[i] = sum1[i - 1] + reg[i - 1];
    }
    for(int i = 1;i<=l2;i++){
        sum2[i] = sum2[i - 1] + imp[i - 1];
    }
    sum2[l2 + 1] = INF;
    int tot;
    int ans = -1;
    for(int i = 0;i<=l1;i++){
        tot = m - sum1[i];
        int res = binarySearch(tot);
        if(res == l2 + 1) continue;
        if(ans == -1) ans = res * 2 + i;
        else ans = min(ans, res * 2 + i);
    }
    cout<<ans<<endl;
}

signed main() {
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
