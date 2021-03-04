#include <iostream>
using namespace std;

string s;
int n, L, M, S;

int nums[4][4]; //  1 L, 2 M, 3 J

int ans;
void solve(){
    ans += min(nums[1][2], nums[2][1]);
    nums[1][2] -= min(nums[1][2], nums[2][1]);
    nums[1][1] += min(nums[1][2], nums[2][1]);
    nums[2][1] -= min(nums[1][2], nums[2][1]);
    nums[2][2] += min(nums[1][2], nums[2][1]);
    ans += min(nums[1][3], nums[3][1]);
    nums[1][3] -= min(nums[1][3], nums[3][1]);
    nums[1][1] += min(nums[1][3], nums[3][1]);
    nums[3][1] -= min(nums[1][3], nums[3][1]);
    nums[3][3] += min(nums[1][3], nums[3][1]);
    ans += min(nums[2][3], nums[3][2]);
    nums[2][3] -= min(nums[2][3], nums[3][2]);
    nums[2][2] += min(nums[2][3], nums[3][2]);
    nums[3][2] -= min(nums[2][3], nums[3][2]);
    nums[3][3] += min(nums[2][3], nums[3][2]);
    ans += nums[1][2] * 2;
    ans += nums[1][3] * 2;
}

int main() {
    cin>>s;
    n = s.size();
    s = "@" + s;
    for(int i =1;i<=n;i++){
        if(s[i] == 'L'){
            L++;
        } else if(s[i] == 'M'){
            M++;
        } else if(s[i] == 'S'){
            S++;
        }
    }
    ans = 0;
    for(int i = 1;i<=L;i++){
        if(s[i] == 'L'){
            nums[1][1] ++;
        } else if(s[i] == 'M'){
            nums[1][2] ++;
        } else {
            nums[1][3] ++;
        }
    }
    for(int i = L + 1;i<=L + M;i++){
        if(s[i] == 'L'){
            nums[2][1] ++;
        } else if(s[i] == 'M'){
            nums[2][2] ++;
        } else {
            nums[2][3] ++;
        }
    }
    for(int i = L + M + 1;i<=n;i++){
        if(s[i] == 'L'){
            nums[3][1] ++;
        } else if(s[i] == 'M'){
            nums[3][2] ++;
        } else {
            nums[3][3] ++;
        }
    }

    solve();

    cout<<ans<<endl;
    return 0;
}
