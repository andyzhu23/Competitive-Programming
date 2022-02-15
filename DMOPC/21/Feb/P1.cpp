#include <bits/stdc++.h>
using namespace std;

bool flag = 0;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int d; cin>>d;
    string s; cin>>s;
    for(int i = 0;i<s.size() - 1;++i) {
        if(s[i] < s[i + 1]) {
            swap(s[i], s[i + 1]);
            cout<<s<<'\n';
            return 0;
        }
    }
    cout<<s<<'\n';
    // for(int i = s.size() - 2;i>=0;--i) {
    //     if(s[i] == s[i + 1]) {
    //         cout<<s<<'\n';
    //         return 0;
    //     }
    // }
    // swap(s[s.size() - 1], s[s.size() - 2]);
    // cout<<s<<'\n';
    return 0;
}