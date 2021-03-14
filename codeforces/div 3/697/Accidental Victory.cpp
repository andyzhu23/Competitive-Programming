/*
 * for this question, sort the players in order from smallest to biggest.
 * We know for sure that if the kth player is possible to win, then any player greater than the kth player is
 * possible to win no matter what. Because the k + ith player can just absorb all k players before and also has his
 * own points as well
 *
 * knowing that, we then need to calculate the dividing point between possible winners,
 * and destined loser(like me in CCC 2021 :-(). We can use binarySearch to quickly find the dividing point.
 *
 * note that we still need the original position of each player in order to give correct answers.
 * Therefore I used a pair and the first value is the token and the second is the ID of the player
 */

#include <iostream>
#include <algorithm>
#define p pair<int, int>
#define f first
#define s second
#define int long long
using namespace std;
const int N = 2e5 + 20;
int n , t;
p a[N];
int res[N];
bool isok(int x){
    int sum = 0;
    for(int i = 1;i<=n;i++){
        if(a[i].f <= x){
            sum += a[i].f;
        } else {
            if(sum >= a[i].f){
                sum += a[i].f;
            } else return false;
        }
    }
    return true;
}

int binarySearch(){
    int l = 1, r = n, mid, ans;
    while(l <= r){
        mid = (l + r) / 2;
        if(isok(a[mid].f)){
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    return ans;
}

void solve(){
    cin>>n;
    for(int i =1;i<=n;i++){
        cin>>a[i].f;
        a[i].s = i;
    }
    sort(a + 1, a + n + 1);
    int ans = binarySearch();
    cout<< n - ans + 1<<endl;
    int len = 0;
    for(int i = ans; i<=n; i++){
        res[++len] = a[i].s;
    }
    sort(res + 1, res + len + 1);
    for(int i = 1;i<=len;i++) cout << res[i]<<" ";
    cout<<endl;
}

signed main() {
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
