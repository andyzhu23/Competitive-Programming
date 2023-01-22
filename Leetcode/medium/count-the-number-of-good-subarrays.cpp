using ll = long long;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int j = -1;
        map<int, ll> cnt;
        ll ans = 0;
        ll mx = 0;
        for(int i = 0;i<nums.size();++i) {
            while(j < (int)nums.size() && mx < k) {
                ++j;
                if(j == nums.size()) break;
                mx -= cnt[nums[j]] * (cnt[nums[j]] - 1) / 2;
                ++cnt[nums[j]];
                mx += cnt[nums[j]] * (cnt[nums[j]] - 1) / 2;
            }
            ans += nums.size() - j;
            mx -= cnt[nums[i]] * (cnt[nums[i]] - 1) / 2;
            --cnt[nums[i]];
            mx += cnt[nums[i]] * (cnt[nums[i]] - 1) / 2;

        }
        return ans;
    }
};
