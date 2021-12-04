#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
template<typename T1, typename T2> using um = unordered_map<T1, T2>;
template<typename T> inline void ckmin(T& a, T b) {a = min(a, b);}
template<typename T>
inline void print(T x) {
    if(x == 0) return;
    print(x / 10);
    putchar(x % 10 + '0');
}
um<char, int> idx;
int cnt[50][50];
int tot = 0, n, dp[10000000];
string s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char c = getchar();
    while(isalpha(c)) s += c, c = getchar();
    if(idx[s[0]] == 0) idx[s[0]] = ++tot;
    for(int i = 1;i<s.size();++i) 
        if(idx[s[i]] == 0) idx[s[i]] = ++tot;
    n = tot;
    dp[0] = 1;
    for(int i = 1;i<s.size();++i) 
        cnt[idx[s[i - 1]] - 1][idx[s[i]] - 1]++;
    for(int i = 1;i<(1 << n);++i) {
        dp[i] = s.size();
        for(int j = 0;j<=20;++j) {
            if(i & (1 << j)) {
                int res = 0;
                for(int k = 0;k<=20;++k) 
                    if(i & (1 << k)) res += cnt[j][k];
                ckmin(dp[i], dp[i ^ (1 << j)] + res);
            }
        }
    }
    print(dp[(1 << n) - 1]);
    putchar('\n');
    return 0;
}
