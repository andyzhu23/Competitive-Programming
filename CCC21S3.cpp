


/*
 * Prefix sum, binary search, enumerate
 *
 *
 * Using prefix-sum to obtain all the sums of wi and all the sums of pi - di for the left and pi + di for right
 * enumerate all possibilities as it is only possible on one of the pi + di or pi - di
 * binarySearch for the left endpoint and right endpoint
 * time complexity O(n log n)
 *
 */


#include <iostream>
#include <algorithm>
#include <vector>
#define vi vector<int>
#define f first
#define s second
#define ll long long
#define pair pair<ll,ll>
#define pb push_back
using namespace std;

const int N = 2e5 + 10;
ll n, p[N], w[N], d[N];

pair l[N], wl[N], r[N], wr[N];//first is the position, second is the value of prefix and suffix sum
vi Map;
//get the first point smaller than x
ll binarySearch1(ll x){
    ll a = 1, b = n, mid, ans = 0;
    while(a <= b){
        mid = (a + b) / 2;
        if(l[mid].f < x){
            ans = mid;
            a = mid + 1;
        } else b = mid - 1;
    }
    return ans;
}
//get the first point bigger than x
ll binarySearch2(ll x){
    ll a = 1, b = n, mid, ans = n;
    while(a <= b){
        mid = (a + b) / 2;
        if(r[mid].f > x){
            ans = mid;
            b = mid - 1;
        } else a = mid + 1;
    }
    return ans;
}

int main(){
    cin>>n;

    //reading input and get all possible points
    for(ll i = 1;i<=n;i++){
        cin>>p[i] >> w[i] >> d[i];
        if(p[i] > d[i]) Map.pb(p[i] - d[i]);
        else Map.pb(0);
        Map.pb(p[i] + d[i]);
    }
    //initialize all the values we need
    for(ll i = 0;i<=n + 1;i++){
        l[i].f = wl[i].f = p[i] + d[i];
        r[i].f = wr[i].f = p[i] - d[i];
        l[i].s = (p[i] + d[i]) * w[i];
        wl[i].s = wr[i].s = w[i];
        if(p[i] - d[i] > 0) r[i].s += (p[i] - d[i]) * w[i];

    }
    //sort it so that the points go from smallest to biggest
    sort(Map.begin(), Map.end());
    sort(l + 1, l + n + 1);
    sort(r + 1, r + n + 1);
    sort(wl + 1, wl + n + 1);
    sort(wr + 1, wr + n + 1);

    //turn the left values we obtained into prefix sum
    for(ll i = 1;i<=n + 1;i++){

        l[i].s += l[i - 1].s;
        wl[i].s += wl[i - 1].s;
    }

    //turn the right values we obtained into suffix sum
    for(ll i = n;i >= 0;i--){
        r[i].s += r[i + 1].s;
        wr[i].s += wr[i + 1].s;
    }

    ll ans = -1;
    //enumerate all possible values
    for(int c : Map){
        ll x = binarySearch1(c);
        ll y = binarySearch2(c);
        ll res = abs(c * wl[x].s - l[x].s); // calculate left result
        res += abs(c * wr[y].s - r[y].s); // calculate right result
        if(ans == -1){
            ans = res;
        } else ans = min(ans, res);
    }
    cout<<ans<<endl;
    return 0;
}
