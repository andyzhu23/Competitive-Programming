#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e4;
struct input{
    int id, x, y;
}inp[N];

struct cow{
    int u,v,w;
};
vector<cow> cows;

int n,x,y,u,v,w,ans,Fu,Fv,f[N];

bool cmp(cow a, cow b){
    return a.w<b.w;
}

int Find(int num){
    if(num == f[num]){
        return num;
    }
    return f[num] = Find(f[num]);
}

void kruskal(){
    for(int i = 1;i<=n;i++) f[i] = i;
    sort(cows.begin(),cows.end(),cmp);

    for(int i = 0;i<cows.size();i++){
        u = cows[i].u;
        v = cows[i].v;
        w = cows[i].w;
        Fu = Find(u);
        Fv = Find(v);
        if(Fu != Fv){
            f[Fu] = Fv;
            ans = w;
        }
    }
}

int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>x>>y;
        inp[i].x = x;
        inp[i].y = y;
        inp[i].id = i;
    }
    cow cur;
    for(int i = 1;i<n;i++){
        for(int j = i+1;j<=n;j++){
            cur.u = inp[i].id;
            cur.v = inp[j].id;
            cur.w = (inp[i].x - inp[j].x)*(inp[i].x - inp[j].x) + (inp[i].y - inp[j].y)*(inp[i].y - inp[j].y);
            cows.push_back(cur);
        }
    }
    kruskal();
    cout<<ans;
    return 0;
}
