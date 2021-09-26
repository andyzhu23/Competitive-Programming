class Solution {
public:
    struct DSU {
        vector<int> f;
        int n;
        DSU(int n) :n(n) {
            f = vector<int>(n + 1);
            for(int i = 0;i<=n;++i) f[i] = i;
        }  
        int Find(int x) {return f[x] == x ? x : Find(f[x]);}
        int merge(int u, int v) {
            int fu = Find(u);
            int fv = Find(v);
            if(fu == fv) return 0;
            f[fu] = fv;
            return 1;
        }
    };
    int n, m;
    
    int id(int x, int y) {return (x - 1) * m + y;}
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        DSU dsu(n * m);
        for(int i = 0;i<n;++i) {
            for(int j = 0;j<m;++j) {
                if(grid[i][j] == '0') continue;
                if(j && grid[i][j] == grid[i][j - 1]) dsu.merge(id(i + 1, j + 1), id(i + 1, j));
                if(i && grid[i][j] == grid[i - 1][j]) dsu.merge(id(i + 1, j + 1), id(i, j + 1));
            }
        }
        set<int> vis;
        for(int i = 0;i<n;++i) {
            for(int j = 0;j<m;++j) {
                if(grid[i][j] == '1') vis.insert(dsu.Find(id(i + 1, j + 1)));
            }
        }
        return int(vis.size());
    }
};
