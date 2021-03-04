#include <iostream>
#include <queue>
#define p pair<int, int>
#define f first
#define s second
using namespace std;
const int N = 1e5 + 10;
int n, t, k, a, cont[N], cnt;
queue<p> dock;
int main() {
    cin>>n;
    cnt = 0;
    for(int i =1 ;i<=n;i++){
        cin>>t>>k;
        for(int j = 1;j<=k;j++){
            cin>>a;
            dock.push(make_pair(a,t));
            cont[a] ++;
            if(cont[a] == 1) cnt++;
        }
        while(!dock.empty() && t - dock.front().s >= 86400){
            p b = dock.front(); dock.pop();
            cont[b.f] --;
            if(cont[b.f] == 0) cnt--;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
