#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 1e4 + 10;

template <typename T> struct BST{
    T val[N], lc[N], rc[N], cnt[N], tot, root;
    void insert(int& rt, int x) {
        if(rt == 0) {
            rt = ++tot;
            val[rt] = x;
            return;
        }
        if(val[rt] == x) cnt[rt] ++;
        else if(val[rt] > x) insert(lc[rt], x);
        else insert(rc[rt], x);
    }
    int Find(int rt, int x) {
        if(val[rt] == x) return rt;
        if(val[rt] > x) return Find(lc[rt], x);
        else return Find(rc[rt], x);
    }
};

BST<int> bst;
int n, a[N];
map<int, int> id;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        bst.insert(bst.root, a[i]);
        id[a[i]] = i;
    }

    for(int i = 1;i<=n;i++) {
        int ans = bst.Find(bst.root, a[i]);
        cout<<i<<": ";
        if(bst.val[bst.lc[ans]] == 0) cout<<'#'<<" ";
        else cout<<id[bst.val[bst.lc[ans]]]<<" ";

        if(bst.val[bst.rc[ans]] == 0) cout<<'#';
        else cout<<id[bst.val[bst.rc[ans]]];
        cout<<'\n';
    }

    return 0;
}
