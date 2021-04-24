#include <iostream>
#include <cmath>
#define endl "\n"
using namespace std;
using ll = long long;
ll n;

inline bool isPrime(ll x){
    for(ll i = 2;i * i <= x;i++){
        if(x % i == 0) return false;
    }
    return true;
}

inline ll solve(){
    cin>>n;
    ll a = -1, b = -1, c = -1;
    ll ans;
    ll m = ll(sqrt(n));
    ll i = m + 1;
    while(i--){
        if(isPrime(i)){
            if(a == -1) a = i;
            else b = i;
        }
        if(a != -1 && b != -1) break;
    }
    i = m;
    while(i ++){
        if(isPrime(i)){
            c = i;
            break;
        }
    }
    ans = max(a * b, a * c <= n ? a * c : 0);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    for(int i = 1;i<=t;i++){
        cout<<"Case #" << i << ": "<< solve() << endl;
    }
    return 0;
}
