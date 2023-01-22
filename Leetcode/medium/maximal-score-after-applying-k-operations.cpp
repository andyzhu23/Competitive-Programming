class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for(auto x : nums) heap.push(x);
        long long ans = 0;
        while(k--) {
            int u = heap.top(); heap.pop();
            ans += u;
            heap.push((u - 1) / 3 + 1);
        }
        return ans;
    }
};
