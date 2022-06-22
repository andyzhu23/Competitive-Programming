#include <bits/stdc++.h>
using namespace std;
string s, t;
bool ok[20][20];

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>s>>t;
    for(char i = 'a';i<='r';++i) {
        for(char j = 'a';j<='r';++j) {
            string x, y;
            for(auto c : s) if(c == i || c == j) x += c;
            for(auto c : t) if(c == i || c == j) y += c;
            ok[i][j] = x == y;
        }
    }
    int q; cin>>q;
    while(q--) {
        bool flag = 1;
        string x; cin>>x;
        for(auto c : x) {
            for(auto d : x) {
                flag &= ok[c][d];
            }
        }
        putchar(flag ? 'Y' : 'N');
    }
    putchar('\n');
    return 0;
}