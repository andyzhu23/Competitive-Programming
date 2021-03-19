/*
 * This question is a very interesting one. The first idea comes to our mind is that we can sort all the cords,
 * then after that we can enumerate all roomba and find how many cords in between 0 to xi of the roomba has
 * y greater than the y of the roomba. To get partial marks, all we need to do is to enumerate all the cords
 * every time when we enumerate y. However, that is too slow to get full mark. You cannot use binary search as
 * sorting the y will definitely make x unordered. There are many ways to approach this problem, but what I am
 * going to do is to use block matrix. I separate all the cords into root m blocks each size of root m. Therefore,
 * I can enumerate the block that the roomba is in with root m time complexity, and then for other blocks, I
 * can enumerate them and use binary search which will not effect the order.
 */


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define f first
#define s second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
const int N = 2e5 + 10;
p roomba[N], cord[N];
int block[N];
int b[N], a[N];
int n, m, bsize;

bool cmp(int x, int y){
    return x > y;
}

// resort the current block
void resort(int pos){
    int x = (pos - 1) * bsize + 1;
    int y = min(m, pos * bsize);
    sort(b + x, b + y + 1, cmp);
}

// find the last one greater than x
int binarySearch2(int pos, int x){
    int l = (pos - 1) * bsize + 1;
    int L = l - 1;
    int ans = L;
    int r = pos * bsize;
    while(l <= r){
        int mid = (l + r) / 2;
        if(b[mid] >= x){
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans - L;
}

// find the last value that x is greater than
int binarySearch1(int x){
    int l = 1, r = m, ans = 0, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(cord[mid].f <= x){
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int getAns(int r, int c){
    r = binarySearch1(r);
    if(r == 0) return 0;
    int ans = 0;
    if(block[r] == 1){
        for(int i = 1; i <= r;i ++){
            if(a[i] >= c) ans ++;
        }
        return ans;
    }
    for(int i = (block[r] - 1) * bsize + 1; i <= r;i++){
        if(a[i] >= c) ans ++;
    }
    for(int i = 1;i < block[r];i++){
        ans += binarySearch2(i, c); // it is i not block[i] here
    }
    return ans;
}

void solve(){
    scanf("%d %d",&n,&m);
    bsize = sqrt(m);
    // reading roomba
    for(int i =1 ;i<=n;i++){
        int x, y;
        scanf("%d %d",&x,&y);
        roomba[i] = mp(x, y);
    }
    ll ans = 0;
    // reading cord
    for(int i = 1;i<=m;i++){
        block[i] = (i - 1) / bsize + 1;
        int x, y;
        scanf("%d %d", &x, &y);
        cord[i] = mp(x, y);
    }
    // sort cord according to x
    sort(cord + 1, cord + m + 1);
    // copy the y to a and b
    for(int i = 1;i<=m;i++){
        a[i] = b[i] = cord[i].s;
    }
    // resort b
    for(int i = 1;i<=block[m];i++){
        resort(i);
    }
    // enumerate roomba
    for(int i = 1;i<=n;i++){
        ans += getAns(roomba[i].f, roomba[i].s);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}
