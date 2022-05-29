/*
 * Complete the 'findMatch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING word
 *  2. STRING guesses
 */
set<int> vow = {'a', 'e', 'i', 'o', 'u'};
struct node {
    string a, b;
    bool operator<(const node& other) const {
        int cnt = 0, cnt2 = 0;
        for(auto x : a) cnt += x == 'G';
        for(auto x : other.a) cnt2 += x == 'G';
        if(cnt != cnt2) return cnt > cnt2;
        cnt = 0, cnt2 = 0;
        for(auto x : a) cnt += x == 'Y';
        for(auto x : other.a) cnt2 += x == 'Y';  
        if(cnt != cnt2) return cnt > cnt2;
        if(a[0] == 'G' ^ other.a[0] == 'G') {
            return a[0] == 'G';
        }
        if(a[4] == 'G' ^ other.a[4] == 'G') {
            return a[4] == 'G';
        }
        cnt = 0, cnt2 = 0;
        for(int i = 0;i<4;++i) {
            if(vow.count(b[i]) && a[i] == 'G') ++cnt;
            if(vow.count(other.b[i]) && other.a[i] == 'G') ++cnt2;
        }
        if(cnt != cnt2) return cnt > cnt2;
        return b < other.b;
    }
};
string findMatch(string word, string guesses) {
    set<char> vis;
    for(char i = 'a';i<='z';++i) vis.insert(i);
    vector<string> a;
    vector<node> ans;
    while(guesses.size() > 5) {
        a.push_back(guesses.substr(0, 5));
        guesses = guesses.substr(6);
    }
    if(guesses.size() == 5) a.push_back(guesses);
    for(auto x : a) {
        string f;
        for(int i = 0;i<5;++i) {
            if(vis.count(x[i])) vis.erase(x[i]);
            if(x[i] == word[i]) f += 'G';
            else f += '-';
        }
        multiset<int> vis;
        for(int i = 0;i<5;++i) if(f[i] != 'G') vis.insert(word[i]);
        for(int i = 0;i<5;++i) if(f[i] == '-'){
            if(vis.count(x[i])) {
                vis.erase(vis.find(x[i]));
                f[i] = 'Y';
            }     
        }
        if(f != "-----") ans.push_back({f, x});
    }
    for(int i = 0;i<ans.size();++i) {
        for(int j = i + 1;j<ans.size();++j) {
            if(!(ans[i] < ans[j])) swap(ans[i], ans[j]);
        }
    }
    cout<<(ans[3] < ans[5])<<'\n';
    if(ans.size() >= 6) {
        string xx;
        for(int i = 0;i<5;++i) xx += ans[i].b + " ";
        xx += ans[5].b;
        return xx;
    }
    string xx;
    for(auto x : vis) xx += x;
    return xx;
}
