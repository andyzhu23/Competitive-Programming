#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;
const int N = 3e5 + 10;
int n, m, d;
struct edge{
    int u, v, w, id;
} e[N];

int f[N], Max;

inline bool cmp(edge a, edge b){
    if(a.w != b.w) return a.w < b.w;
    return a.id < b.id;
}

inline int Find(int x){
    if(f[x] == x) return x;
    return f[x] = Find(f[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>d;
    for(int i = 1;i<=m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        e[i].u = a;
        e[i].v = b;
        e[i].w = c;
        e[i].id = i;
    }
    for(int i = 1;i<=n;i++) f[i] = i;
    sort(e + 1, e + m + 1, cmp);
    int ans = 0;
    int cnt = 0;
    // obtaining the MST using Kruskal Algorithm
    for(int i =1 ;i<=m;i++){
        if(cnt == n - 1) break;
        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;
        int id = e[i].id;
        int fu = Find(u);
        int fv = Find(v);
        if(fu != fv){
            cnt ++;
            f[fu] = fv;
            if(id >= n) ans ++;
            Max = max(Max, w);
        }
    }
    // if all edges are used then the answer is ans
    if(m < n){
        cout<<ans<<endl;
        return 0;
    }
    // the answer is either ans or ans - 1
    // we will only use d on an edge with weight Max
    for(int i = 1;i<=n;i++) f[i] = i;
    for(int i = 1;i<=m;i++){
        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;
        int id = e[i].id;
        int fu = Find(u);
        int fv = Find(v);
        if(fu != fv){
            // if the two sides are not connected, then if the current edge is smaller than Max we use it
            // or if the edge is Max but it is already active then we don't use it because it will not decrease the number of days
            if(e[i].w < Max || (e[i].w == Max && id < n)){
                f[fu] = fv;
            } else if(id < n && w <= d){ 
                // if the edge is active and the weight is smaller than d, we can make this weight 0
                // then we don't need to activate another pipe and deactivate this one
                cout<<ans - 1 << endl;
                return 0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
