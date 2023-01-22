using pii = pair<int, int>;
using ll = long long;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pii> v;
        for(int i = 0;i<n;++i) {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end(), greater<pii>());
        ll ans = 0, tot = 0;
        multiset<int> bst;
        for(int i = 0;i<n;++i) {
            bst.insert(v[i].second);
            tot += v[i].second;
            if(bst.size() > k) {
                tot -= *bst.begin();
                bst.erase(bst.begin());
            }
            if(bst.size() == k)
            ans = max(ans, 1ll * v[i].first * tot);
        }
        return ans;
    }
};
