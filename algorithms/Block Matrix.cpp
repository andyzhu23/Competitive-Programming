#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;
const int N = 5e4 + 10;
int n, bsize, a[N],b[N], block[N], lazy[N];

void resort(int p){
    int x = (p - 1) * bsize + 1;
    int y = min(n, p * bsize);
    for(int i = x;i<=y;i++){
        b[i] = a[i];
    }
    sort(b + x, b + y + 1);
}

void add(int l, int r, int c){
    for(int i = l;i<=min(r, block[l] * bsize);i++){
        a[i] +=c;
    }
    resort(block[l]);
    if(block[l] != block[r]) {
        for (int i = (block[r] - 1) * bsize + 1; i <= r; i++) {
            a[i] += c;
        }
        resort(block[r]);
    }
    for(int i = block[l] + 1;i<block[r]; i++){
        lazy[i] += c;
    }

}

int binarySearch(int l, int r, int x){
    int mid, ans = l - 1;
    while(l <= r){
        mid = ( l + r ) / 2;
        if(b[mid] < x){
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int getAns(int l, int r, int x){
    int ans = 0;
    for(int i = l;i<=min(r, block[l] * bsize);i++){
        if(a[i] + lazy[block[i]] < x) ans ++;
    }
    if(block[l] == block[r]) return ans;
    for(int i = (block[r] - 1) * bsize + 1;i<=r;i++){
        if(a[i] + lazy[block[i]] < x) ans ++;
    }
    for(int i = block[l] + 1;i<block[r]; i++){
        ans += binarySearch((i - 1) * bsize + 1, i * bsize , x - lazy[i]) - (i - 1) * bsize;
    }
    return ans;
}

signed main() {
    cin>>n;
    bsize = sqrt(n);

    for(int i =1;i<=n;i++){
        scanf("%lld",&a[i]);
        block[i] = (i - 1) / bsize + 1;
    }

    for(int i = 1;i<=(n - 1) / bsize + 1;i++){
        resort(i);
    }

    for(int i = 1;i<=n;i++){
        int opt, l, r, c;
        scanf("%lld %lld %lld %lld",&opt,&l,&r,&c);
        if(opt == 0){
            add(l, r, c);
        } else {
            printf("%lld\n", getAns(l, r, c * c));
        }
    }

    return 0;
}
