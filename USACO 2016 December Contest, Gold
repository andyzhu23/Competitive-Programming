#include <iostream>
#include <math.h>
using namespace std;
const int N = 1e3+10;
int n,f[N],fi,fj;
long long ans;
struct cow{
    int x,y;
}cows[N];

long long dist(long long a, long long b){
    long long x = cows[a].x - cows[b].x;
    long long y = cows[b].y - cows[a].y;
    return pow(x,2) + pow(y,2);
}

int Find(int x){
    if(f[x] == x) return x;
    return f[x] = Find(f[x]);
}

bool check(long long mid){
    for(int i = 1;i<=n;i++) f[i] = i;
    for(int i = 1;i<n;i++){
        for(int j = i+1;j<=n;j++){
            if(dist(i,j) <= mid){
                fi = Find(i);
                fj = Find(j);
                if(fi != fj){
                    f[fi] = f[j];
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        cnt+= (f[i] == i);
    }
    return cnt == 1;
}


int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>cows[i].x>>cows[i].y;
    }
    long long l = 0, r = 3e9,mid;
    while(l<=r){
        mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            r = mid -1;
        } else l = mid +1;
    }
    cout<<ans;
    return 0;
}
