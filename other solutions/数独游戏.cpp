#include <bits/stdc++.h>
using namespace std;

int a[10][10], b[10][10], row[10], col[10], grid[10];

int get(int i, int j) {
    --j;
    --i;
    i /= 3;
    j /= 3;
    return ((++i) - 1) * 3 + (++j);
}

bool flag = 0;

void dfs(int x, int y) {
    if(flag) return;
    if(x == 9 && y == 10) {
        for(int i = 1;i<=9;i++) {
            for(int j = 1;j<=9;j++) 
                cout<<b[i][j];
            cout<<'\n';
        }
        flag = 1;
        return;
    }
    if(y == 10) {
        x ++;
        y = 1;
    }
    if(b[x][y]) {
        dfs(x, y + 1);
        return;
    }
    for(int i = 1;i<=9;i++) {
        if(row[x] & (1 << i)) continue;
        if(col[y] & (1 << i)) continue;
        if(grid[get(x, y)] & (1 << i)) continue;
        b[x][y] = i;
        row[x] |= 1 << i;
        col[y] |= 1 << i;
        grid[get(x, y)] |= 1 << i;
        dfs(x, y + 1);
        b[x][y] = 0;
        row[x] ^= 1 << i;
        col[y] ^= 1 << i;
        grid[get(x, y)] ^= 1 << i;
    }
}

int main() {
    #ifnedf ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1;i<=9;i++) {
        for(int j = 1;j<=9;j++) {
            char c; cin>>c;
            a[i][j] = c - '0';
            b[i][j] = a[i][j];
            row[i] |= 1 << a[i][j];
            col[j] |= 1 << a[i][j]; 
            grid[get(i, j)] |= 1 << a[i][j]; 
        }
    }
    dfs(1, 1);
    return 0;
}
