class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(auto x : nums2) s.insert(x);
        for(auto x : nums1) {
            if(s.count(x)) {
                return x;
            }
        }
        return -1;
    }
};
