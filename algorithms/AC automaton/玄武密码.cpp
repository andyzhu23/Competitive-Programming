#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

string a[100001];

int n, m;

struct Trie {
    int fail[N], tr[N][26], cnt[N], tot = 0, res[N];
    void update(string& s, int num) {
        int cur = 0;
        for(int c : s) {
            c -= 'A';
            if(!tr[cur][c]) tr[cur][c] = ++tot;
            cur = tr[cur][c];

            int u = cur;
        }
        cnt[cur] = num;
    }

    void build() {
        queue<int> q;
        for(int i = 0;i<26;++i) {
            if(tr[0][i]) q.push(tr[0][i]);
        }
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int i = 0;i<26;++i) {
                if(tr[cur][i]) fail[tr[cur][i]] = tr[fail[cur]][i], 
                    q.push(tr[cur][i]);
                else tr[cur][i] = tr[fail[cur]][i];
            }
        }
    }

    int cal(string& s) {
        int cur = 0;
        int ans = 0;
        for(char c : s) {
            c -= 'A';
            cur = tr[cur][c];
            ans += res[cur];
        }
        return ans;
    }

    void query(string& s) {
        int lst = 0;
        for(int c : s) {
            c -= 'A';
            lst = tr[lst][c];
            for(int i = lst;i != 0 && res[i] != 1; i = fail[i]) res[i] = 1;
        }
        for(int i = 1;i<=m;++i) {
            cout<<cal(a[i])<<'\n';
        }
    }
} trie;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string s; cin>>s;
    for(int i = 1;i<=m;++i) {
        cin>>a[i];
        
        trie.update(a[i], i);
    }
    trie.build();
    trie.query(s);
    return 0;
}
