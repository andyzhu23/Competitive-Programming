#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin>>s>>t;
    int i;
    for(i = 0;i<min(s.size(), t.size());i++){
        if(s[i] == t[i]) continue;
        else {
            break;
        }
    }
    cout<<s.size() + t.size() - 2 * i<<endl;
    return 0;
}
