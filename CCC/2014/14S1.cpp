#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;
using ll = long long;
int n, m;
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++) q.push(i);
    cin>>m;
    while(m--){
        int cnt = 0;
        int sz = q.size();
        int r;
        cin>>r;
        for(int i = 1;i<=sz;i++){
            int cur = q.front();
            q.pop();
            ++cnt;
            if(cnt % r != 0){
                q.push(cur);
            }
        }
    }
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
