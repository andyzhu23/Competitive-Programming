#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair

using pii = pair<int, int>;

const int N = 1e5 + 10;
int a[N], n, k;
deque<pii> dq, dq2;
vector<int> b;

int main(){
    cin>>n>>k;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++) {
        while(!dq.empty() && dq.front().second <= i - k){
            dq.pop_front();
        }
        while(!dq.empty() && dq.back().first <= a[i]) {
            dq.pop_back();
        }
        while(!dq2.empty() && dq2.front().second <= i - k) {
            dq2.pop_front();
        }
        while(!dq2.empty() && dq2.back().first >= a[i]) {
            dq2.pop_back();
        }
        dq.push_back(mp(a[i], i));
        dq2.push_back(mp(a[i], i));
        if(i >= k) {
            if(i != n) cout<<dq2.front().first<<" ";
            else cout<<dq2.front().first<<endl;
            b.pb(dq.front().first);
        }
    }
    for(int i = 0;i<b.size() - 1;i++) cout<<b[i]<<" ";
    cout<<b[b.size() - 1]<< endl;
    return 0;
}
