#include <iostream>
#include <unordered_set>
#define ll long long
using namespace std;
 
string solve(){
    ll x;
    cin>>x;
    unordered_set<ll> vis;
    for(ll i = 1;i * i * i <= x;i++){
        ll j = x - i * i * i;
        vis.insert(i * i * i);
        if(vis.count(j)) return "YES";
    }
    return "NO";
}
 
int t;
int main() {
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}
