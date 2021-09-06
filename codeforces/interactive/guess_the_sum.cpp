#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l = 1, r = 1000000;
    while(l <= r) {
        
        int mid = (l + r + 1) >> 1;
        cout<<mid<<'\n'<<flush;
        string s; cin>>s;
        if(s == "<") {
            r = mid - 1;
        } else l = mid;
        if(l == r) {
            cout<<"! "<<l<<'\n'<<flush;
            break;
        } 
    }
    return 0;
}
