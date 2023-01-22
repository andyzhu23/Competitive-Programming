using ll = long long;
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        if(k == 0) {
            for(int i = 0;i<n;++i) {
                if(nums1[i] != nums2[i]) return -1ll;
            }
            return 0ll;
        }
        for(int i = 0;i<n;++i) {
            if(abs(nums1[i] - nums2[i]) % k) return -1ll;
        }
        ll cnt = 0, cnt2 = 0;
        for(int i = 0;i<n;++i) {
            if(nums1[i] > nums2[i]) cnt += (nums1[i] - nums2[i]) / k;
            if(nums1[i] < nums2[i]) cnt2 += abs(nums1[i] - nums2[i]) / k;
        }
        if(cnt == cnt2) return cnt;
        else return -1ll;
    }
};
