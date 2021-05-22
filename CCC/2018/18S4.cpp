/*
 * this question is just dynamic programming, and you use the smaller subtrees to find the result of the big
 * subtree
 */

#include <cstdio>
#include <unordered_map>
#include <ios>
using namespace std;
using ll = long long;
unordered_map <ll, ll> f;
int n;

inline void FindTree(int a){
    if(a == 1 || a == 2) return;
    // the next possible number of trees which the weight will differ
    int nxt;
    for(int k = a;k>=2;k = nxt){
        // if already computed, use the result
        if(f[a/k] == 0) FindTree(a/k);
        // calculate the next nxt
        // anything smaller than nxt has subtrees of weights that are different
        // a / k + 1 indicate the next weight of subtrees
        nxt = a / (a / k + 1);
        // we know that from k to k - nxt, the weight of subtrees are the same so we just multiply
        f[a] += f[a/k] * (k - nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    scanf("%d", &n);
    // initializing
    f[1] = 1;
    f[2] = 1;
    FindTree(n);
    printf("%lld", f[n]);
    return 0;
}
