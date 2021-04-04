#include <iostream>
#define endl "\n"
using namespace std;

string s;

char dir[] = {'@', 'N', 'E', 'S', 'W', 'N'};

int getDir(char a, char b){
    if(a == b) return 0;
    for(int i = 1;i <= 5; i++){
        if(dir[i] == a && dir[i + 1] == b) return 1;
    }
    return -1;
}

int solve(){
    cin>>s;
    int len = s.size();
    s = "@" + s;
    int ans = 0;
    for(int i = 1;i<len;i++){
        ans += getDir(s[i], s[i + 1]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    while(n --){
        int ans = solve();
        if(ans < 0) cout<<"CCW"<<endl;
        else cout<<"CW"<<endl;
    }
    return 0;
}
