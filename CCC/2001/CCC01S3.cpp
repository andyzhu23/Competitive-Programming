#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3;
string s[N];
int a[N][2], f[N];
vector<int> ans;

int Find(int x){
    if(x == f[x]) return x;
    return f[x] = Find(f[x]);
}

void Union(int fu, int fv){
    for(int i = 1;i<N;i++){
        if(f[i] == fu){
            f[i] = fv;
        }
    }
}

int main(){
    int n = 0;
    while(true){
        cin>>s[++n];
        if(s[n] == "**") break;
        a[n][0] = s[n][0] - 'A' + 1;
        a[n][1] = s[n][1] - 'A' + 1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<N;j++) f[j] = j;
        for(int j = 1;j<=n;j++){
            if(i == j) continue;
            int u = a[j][0];
            int v = a[j][1];
            int fu = Find(u);
            int fv = Find(v);
            Union(fu,fv);
        }
        if(f[1] != f[2]){
            ans.push_back(i);
        }
    }
    for(int i = 0;i<ans.size();i++){
        int j = ans[i];
        cout<<s[j][0]<<s[j][1]<<endl;
    }
    cout<<"There are "<<ans.size()<< " disconnecting roads."<<endl;
}
