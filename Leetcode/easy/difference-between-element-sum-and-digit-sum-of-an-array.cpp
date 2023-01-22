class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto x : nums) {
            a += x;
            while(x > 0) {
                b += x % 10;
                x /= 10;
            }
        }
        return abs(a - b);
    }
};
