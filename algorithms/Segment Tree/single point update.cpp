#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll sum[N << 2];
int n, m;

void push_up(int rt){
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int rt, int l, int r, int a, int b)
{
    if(l == r && l == a){
        sum[rt] += b;
        return;
    }
    int mid = (l + r) >> 1;
    if(a <= mid) update(rt << 1, l, mid, a, b);
    else update(rt << 1 | 1, mid + 1, r, a, b);
    push_up(rt);
}

ll query(int rt, int l, int r, int a, int b)
{
    if(l == a && r == b){
        return sum[rt];
    }
    int mid = (l + r) >> 1;
    if(b <= mid) return query(rt << 1, l, mid, a, b);
    else if(a > mid) return query(rt << 1 | 1, mid + 1, r, a, b);
    else return query(rt << 1, l, mid, a, mid) + query(rt << 1 | 1, mid + 1, r, mid + 1, b);
}

int main(){
    cin>>n>>m;
    while(m --){
        int k, a, b;
        scanf("%d %d %d", &k, &a, &b);
        if(k){
            printf("%lld\n", query(1, 1, n, a, b));
        } else {
            update(1, 1, n, a, b);
        }
    }
    return 0;
}
