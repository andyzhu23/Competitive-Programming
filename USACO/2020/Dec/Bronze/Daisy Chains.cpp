#include <iostream>
using namespace std;
int n, flower[104], ans = 0;

bool isOk(int l, int r){
    int total = 0;
    int num = r-l+1;
    for(int i = l;i<=r;i++){
        total +=flower[i];
    }
    if(total % num !=0) return false;
    int average = total / (r-l+1);
    for(int i = l;i<=r;i++){
        if(flower[i]==average) return true;
    }
    return false;
}

void solve(){
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            if(isOk(i,j)){
                ans++;
            }
        }
    }
}

int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>flower[i];
    }
    ans = 0;
    solve();
    cout<<ans;
    return 0;
}
