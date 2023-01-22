class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<char, int> mp, mp2;
        for(auto x : word1) ++mp[x];
        for(auto x : word2) ++mp2[x];
        int x = mp.size(), y = mp2.size();
        for(auto[u, v] : mp) {
            for(auto[a, b] : mp2) {
                if(v > 0 && b > 0) {
                int xx = x;
                int yy = y;
                if(v == 1) --xx;
                mp[u]--;
                if(mp[a] == 0) ++xx;
                mp[a]++;
                if(b == 1) --yy;
                mp2[a]--;
                if(mp2[u] == 0) ++yy;
                mp2[u]++;
                cout<<u<<' '<<mp[u]<<' '<<a<<' '<<mp2[a]<<' '<<xx<<' '<<yy<<'\n';
                if(xx == yy) return 1;
                mp[u]++;
                mp[a]--;
                mp2[u]--;
                mp2[a]++;
                }
            }
        }
        return 0;
    }
};
