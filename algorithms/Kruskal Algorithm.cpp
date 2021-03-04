#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6;
int n,m,a,b,c,Fa,Fb;
long long ans;
int f[N];
struct point{
    int a,b,c;
}e[N];
bool cmp(point a, point b){
    return a.c<b.c;
}
int Find(int x){
    if(x == f[x]) return x;
    return f[x] = Find(f[x]);
}

int main() {
    ans = 0;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++) f[i] = i;
    for(int i = 1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        e[i].a = a;
        e[i].b = b;
        e[i].c = c;
    }
    sort(e+1,e+m+1,cmp);
    for(int i =1 ;i<=m;i++){
        int a = e[i].a;
        int b = e[i].b;
        int c = e[i].c;
        Fa = Find(a);
        Fb = Find(b);
        if(Fa != Fb){
            ans += c;
            f[Fa] = Fb;
        }
    }
    printf("%lld",ans);
    return 0;
}
