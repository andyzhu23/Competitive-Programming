#include <iostream>
using namespace std;

inline int solve(){
    int opt, x;
    cin>>opt>>x;
    if(opt == 1) return x >> 1;
    if(opt == 2) return x << 1;
    if(opt == 3) return x << 1 | 1;
    if(opt == 4) return (x | 1) ^ 1;
    if(opt == 5) return x | 1;
    if(opt == 6) return x ^ 1;
    if(opt == 10) return x & 7;
    if(opt == 15) return x & (x + 1);
    if(opt == 16) return x | (x + 1);
    if(opt == 17) return x | (x - 1);
    if(opt == 18) return (x ^ (x + 1)) >> 1;
    if(opt == 19) return x & (-x);
    int k; cin>>k;
    if(opt == 7) return x | (1 << (k - 1));
    if(opt == 8) return (x | (1 << (k - 1))) ^ (1 << (k - 1));
    if(opt == 9) return (x ^ (1 << (k - 1)));
    if(opt == 11) return x & ((1 << k) - 1);
    if(opt == 12) return (x & (1 << (k - 1))) >> (k - 1);
    if(opt == 13) return x | ((1 << k) - 1);
    if(opt == 14) return x ^ ((1 << k) - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}

/*

19
1 45
2 45
9 41 3
3 45
4 45
5 44
6 45
7 45 3
8 45 3
9 41 3
10 109
11 109 4
12 109 4
13 41 4
14 41 4
15 303
16 303
17 408
18 303
19 408

19
10110
1011010
1011011
101100
101101
101100
101101
101001
101101
101
1101
1
101111
100110
100100000
100111111
110011111
1111
1000

*/
