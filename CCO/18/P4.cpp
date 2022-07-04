#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int r, c, k;

int coor[3][2] = {{1, 2}, {1, 4}, {1, 10}};

int query(int p, int q) {
    printf("? %d %d\n", p, q);
    fflush(stdout);
#ifdef LOCAL
    int ret = 0;
    for(auto x : coor) {
        ret += abs(p - x[0]);
        ret += abs(q - x[1]);
    }
    printf("%d\n", ret);
    return ret;
#endif
    int x; scanf("%d", &x);
    return x;
}

int main(){
    scanf("%d%d%d", &r, &c, &k);
    int lox = 1, hix = r, loy = 1, hiy = c;
    int u = 1, v = 1;
    while(lox <= hix || loy <= hiy) {
        int midx = lox <= hix ? lox + hix >> 1 : u;
        int midy = loy <= hiy ? loy + hiy >> 1 : v;
        int a = query(midx, midy);
        if(lox <= hix) {
            if(midx == r) {
                u = midx;
                lox = hix + 1;
            } else {
                int b = query(midx + 1, midy);
                if(a > b) u = midx + 1, lox = midx + 1;
                else u = midx, hix = midx - 1;
            }
        }
        if(loy <= hiy) {
            if(midy == c) {
                v = midy;
                loy = hiy + 1;
            } else {
                int c = query(midx, midy + 1);
                if(a > c) v = midy + 1, loy = midy + 1;
                else v = midy, hiy = midy - 1;
            }
        }
    }
    printf("! %d\n", query(u, v));
    return 0;
}
