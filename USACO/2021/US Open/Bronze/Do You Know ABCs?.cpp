#include <iostream>
#include <memory.h>
#include <algorithm>
#include <unordered_set>
#define endl "\n"
using namespace std;
int n, a[10], nums[10], ans, nums1[10];
unordered_set<string> vis;

inline bool isok(){
    for(int i = 1;i<10;i++)nums[i] = nums1[i];
    if(!nums[1] && !nums[2] && !nums[3]){
        nums[3] = nums[7] - nums[4];
        nums[1] = nums[7] - nums[6];
        nums[2] = nums[7] - nums[5];
    } else if(!nums[1] && !nums[2] && nums[3]){
        if(nums[6]) nums[2] = nums[6] - nums[3];
        if(nums[5]) nums[1] = nums[5] - nums[3];
    } else if(!nums[1] && nums[2] && !nums[3]){
        if(nums[6]) nums[3] = nums[6] - nums[2];
        if(nums[4]) nums[1] = nums[4] - nums[2];
    } else if(nums[1] && !nums[2] && !nums[3]){
        if(nums[4]) nums[2] = nums[4] - nums[1];
        if(nums[5]) nums[3] = nums[5] - nums[1];
    }
    if(nums[1] && nums[2] && !nums[3]){
        if(nums[5]) nums[3] = nums[5] - nums[1];
        else if(nums[6]) nums[3] = nums[6] - nums[2];
        else if(nums[7]) nums[3] = nums[7] - nums[1] - nums[2];
    } else if(nums[1] && !nums[2] && nums[3]){
        if(nums[4]) nums[2] = nums[4] - nums[1];
        else if(nums[6]) nums[2] = nums[6] - nums[3];
        else if(nums[7]) nums[2] = nums[7] - nums[1] - nums[3];
    } else if(!nums[1] && nums[2] && nums[3]){
        if(nums[4]) nums[1] = nums[4] - nums[2];
        else if(nums[5]) nums[1] = nums[5] - nums[3];
        else if(nums[7]) nums[1] = nums[7] - nums[3] - nums[2];
    }
    if(nums[4] && nums[4] != nums[1] + nums[2]) return false;
    if(nums[5] && nums[5] != nums[1] + nums[3]) return false;
    if(nums[6] && nums[6] != nums[2] + nums[3]) return false;
    if(nums[7] && nums[7] != nums[1] + nums[2] + nums[3]) return false;
    for(int i = 1;i<=7;i++) if(nums[i] < 0) return false;
    if(nums[1] > nums[2] || nums[2] > nums[3]) return false;
    string b = to_string(nums[1]) + to_string(nums[2]) + to_string(nums[3]);
    if(vis.count(b)) return false;
    vis.insert(b);
    //cout<<nums[1]<<" "<<nums[2]<<" "<<nums[3]<<endl;
    return true;
}

inline void dfs(int index, int pos){
    nums1[pos] = a[index];
    if(pos == 7 || index > n){
        ans += isok();
        swap(nums1[4], nums1[3]);
        ans += isok();
        swap(nums1[3], nums1[4]);
        return;
    }
    for(int i = pos + 1; i <= 7 - n + index + 1; i++){
        dfs(index + 1, i);
        nums1[i] = 0;
    }

}

inline int solve(){
    cin>>n;
    ans = 0;
    vis.clear();
    memset(nums, 0, sizeof(nums));
    memset(nums1, 0, sizeof(nums1));
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a + 1, a + n + 1);
    dfs(0, 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cout << solve() << endl;
    }
    return 0;
}
