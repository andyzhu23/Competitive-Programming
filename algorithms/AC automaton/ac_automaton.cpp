#include <bits/stdc++.h>
using namespace std;

namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    void read(int& x) {x = read();}
    template<typename T> void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
            putchar(x % 10 + '0');
    }
    template<typename T> void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;

int n;
const int N = 1e5 + 10;

struct Trie {
    struct node {
        int rt, fail, cnt, to[26];
    } tr[30 * N];
    int tot = 0;
    void update(string& s) {
        int cur = 0;
        for(auto c : s) {
            if(!tr[cur].to[c - 'a']) tr[cur].to[c - 'a'] = ++tot;
            cur = tr[cur].to[c - 'a'];
        }
        tr[cur].cnt ++;
    }
    void build() {
        vector<int> q(N);
        int l = 0, r = 0;
        for(int i = 0;i<26;++i) {
            if(tr[0].to[i]) q[r++] = tr[0].to[i];
        }
        while(l < r) {
            int cur = q[l++];
            for(int i = 0;i<26;++i) {
                int nxt = tr[cur].to[i];
                if(nxt) tr[nxt].fail = tr[tr[cur].fail].to[i], q[r++] = nxt;
                else tr[cur].to[i] = tr[tr[cur].fail].to[i];
            }
        }
    }
    int query(string& s) {
        int lst = 0, ans = 0;
        for(auto c : s) {
            lst = tr[lst].to[c - 'a'];
            int p = lst;
            while(p != 0 && tr[p].cnt != -1) {
                ans += tr[p].cnt;
                tr[p].cnt = -1;
                p = tr[p].fail;
            }
        }
        return ans;
    }
} trie;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for(int i = 1;i<=n;++i) {
        string s; cin>>s;
        trie.update(s);
    }
    trie.build();
    string s; cin>>s;
    print(trie.query(s), '\n');
    return 0;
}
