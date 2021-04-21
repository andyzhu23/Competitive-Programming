#include <iostream>
#include <cstdio>
#define pushup(rt) Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
int Max[N << 2];
int n, m, a[N];

void build(int rt, int l, int r){
    if(l == r){
        Max[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

int query(int rt, int l, int r, int x, int y){
    if(l == x && y == r){
        return Max[rt];
    }
    int mid = (l + r) >> 1;
    if(y <= mid) return query(rt << 1, l, mid, x, y);
    else if(mid < x) return query(rt << 1 | 1, mid + 1, r, x, y);
    else return max(query(rt << 1, l, mid, x, mid), query(rt << 1 | 1, mid + 1, r, mid + 1, y));
}

int main() {
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    build(1, 1, n);
    for(int i = 1;i<=m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        cout<<query(1, 1, n, a, b)<<endl;
    }
    return 0;
}
