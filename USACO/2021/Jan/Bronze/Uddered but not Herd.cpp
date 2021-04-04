#include <iostream>
#define endl "\n"
using namespace std;
string a, b;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    int cur = 0;
    while(cur < b.size()){
        for(int i = 0;i<26;i++){
            if(a[i] == b[cur]) cur ++;
        }
        ++ans;
    }

    cout<<ans<<endl;
    return 0;
}
