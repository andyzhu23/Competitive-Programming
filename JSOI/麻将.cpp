/*
 * standard enumeration
 */

#include <iostream>
#include <vector>
#include <cmath>
#define int long long
using namespace std;
const int N = 1e4 + 10;
int n, m, a[N], sz, cnt[N], cnt2[N];
bool vis[N];
typedef vector<int> vi;
vi res;

signed main(){
    cin>>n>>m;
    sz = 3 * m + 1;
    for(int i = 1;i<=sz;i++){
        cin>>a[i];
        cnt[a[i]] ++;
    }
    // enumerate 听牌
    for(int i = 1;i<=n;i++){
        cnt[i] ++;
        // enumerate doubles
        for(int j = 1;j<=n;j++){
            if(cnt[j] < 2) continue;
            cnt[j] -= 2;
            for(int k = 1;k<=n;k++){
                cnt2[k] = cnt[k];
            }
            bool flag = true;
            for(int k = 1;k<=n;k++){
                cnt2[k] %= 3;
                if(cnt2[k + 1] < cnt2[k] || cnt2[k + 2] < cnt2[k]){
                    flag = false;
                    break;
                }
                cnt2[k + 1] -= abs(cnt2[k]);
                cnt2[k + 2] -= abs(cnt2[k]);
                cnt2[k] -= abs(cnt2[k]);
            }
            if(flag && !vis[i]){
                vis[i] = true;
                res.push_back(i);
            }
            cnt[j] += 2;
        }
        cnt[i] --;
    }
    if(res.empty()){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i = 0; i< res.size() - 1;i++){
        cout<<res[i] <<" ";
    }
    cout<<res[res.size() - 1];
    return 0;
}
