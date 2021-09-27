class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && nums2.empty()) return 0;
        if(nums1.size() + nums2.size() == 1) {
            if(nums1.size() == 1) return nums1[0];
            else return nums2[0];
        }
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int> > big;
        for(int i : nums1) {
            if(small.empty()) small.push(i);
            else if(i <= small.top()) small.push(i);
            else if(i > small.top()) big.push(i);
            if(big.size() > small.size()) {
                small.push(big.top()); 
                big.pop();
            } else if(small.size() > big.size() + 1) {
                big.push(small.top());
                small.pop();
            }
        }
        for(int i : nums2) {
            if(small.empty()) small.push(i);
            else if(i <= small.top()) small.push(i);
            else if(i > small.top()) big.push(i);
            if(big.size() > small.size()) {
                small.push(big.top()); 
                big.pop();
            } else if(small.size() > big.size() + 1) {
                big.push(small.top());
                small.pop();
            }
        }
        double a = small.top();
        double b = big.top();
        return (small.size() + big.size()) & 1 ? a : (a + b) / 2;
    }
};
