class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int> > ans(n, vector<int>(n));
        for(vector<int> x : queries) {
            ans[x[0]][x[1]] += 1;
            if(x[3] < n - 1) ans[x[0]][x[3] + 1] -= 1;
            if(x[2] < n - 1) ans[x[2] + 1][x[1]] -= 1;
            if(x[3] < n - 1 && x[2] < n - 1) ans[x[2] + 1][x[3] + 1] += 1;
        }
        for(int i = 0;i<n;++i) {
            for(int j = 0;j<n;++j) {
                if(i) ans[i][j] += ans[i - 1][j];
                if(j) ans[i][j] += ans[i][j - 1];
                if(i && j) ans[i][j] -= ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};
