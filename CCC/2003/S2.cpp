#include <bits/stdc++.h>
using namespace std;

string s[5];
unordered_set<char> key = {'a', 'e', 'i', 'o', 'u', ' '};

void solve() {
    for(int i = 1;i<=4;++i) {
        getline(cin, s[i]);
        for(auto& c : s[i]) if(c <= 'Z' && c != ' ') c -= 'A', c += 'a';
        int j = s[i].size() - 1;
        while(j >= 0 && s[i][j] != ' ') --j;
        s[i] = j + 1 == s[i].size() ? "" : s[i].substr(j + 1);
        if(s[i].size() == 0) continue;
        j = s[i].size() - 1;
        while(j > 0 && !key.count(s[i][j])) --j;
        s[i] = s[i].substr(j);
    }
    if(s[1] == s[2] && s[2] == s[3] && s[3] == s[4]) puts("perfect");
    else if(s[1] == s[2] && s[3] == s[4]) puts("even");
    else if(s[1] == s[3] && s[2] == s[4]) puts("cross");
    else if(s[1] == s[4] && s[2] == s[3]) puts("shell");
    else puts("free");
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; cin>>t;
    getline(cin, s[1]);
    while(t--) solve();
    return 0;
}
