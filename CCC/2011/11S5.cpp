#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
using PI = pair<int, int>;
#define endl "\n"
#define f first
#define s second
#define mp make_pair
#define ins insert
const int N = 30;
int k, ans;
vector<int> a(N);
unordered_set<int> vis;
queue<PI> q;

inline void process(int& nxt, int pos){
    int cnt = 0, lft;
    for(int i = pos;i<k;i++){
        if(!((1 << i) & nxt)) break;
        cnt ++;
    }
    for(int i = pos; i >= 0; i--){
        if(!((1 << i) & nxt)) break;
        cnt ++;
        lft = i;
    }
    cnt --;
    if(cnt < 4) return;
    nxt = nxt & (nxt + (1 << lft));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>k;
    for(int i = 0;i<k;i++){
        cin>>a[i];
    }
    int start = 0;
    for(int i = 0;i<k;i++){
        start += a[i] << i;
    }
    q.push(mp(start, 0));
    while(!q.empty()){
        PI shit = q.front(); q.pop();
        if(vis.count(shit.f)) continue;
        vis.ins(shit.f);
        if(shit.f == 0) {
            ans = shit.s;
            break;
        }
        for(int i = 0; i<k;i++){
            if(!(shit.f & (1 << i))) {
                int nxt = shit.f | (1 << i);
                process(nxt, i);
                q.push(mp(nxt, shit.s + 1));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
