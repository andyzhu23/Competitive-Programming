#include <iostream>
#define endl "\n"
using namespace std;
string s;
int n;
inline void solve(){
    cin>>n;
    cin>>s;
    s = "@" + s;
    cout<<1<<" ";
    int cnt = 1;
    for(int i = 2;i<=n;i++){
        if(s[i] > s[i - 1]) cout<<++cnt<<" ";
        else {
            cnt = 1;
            cout<<1<<" ";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    for(int i = 1;i<=t;i++){
        cout<<"Case #" << i << ": ";
        solve(); cout << endl;
    }
    return 0;
}
