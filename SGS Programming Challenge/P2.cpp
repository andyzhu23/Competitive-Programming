#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> ans;
vector<int> a, b;

void get() {
    int c = 0;
    while((1 << c) < n) ++c;
    --c;
    if(c == -1) return;
    cout<<"$ "<<n<<' ';
    for(int i = 0;i<a.size();++i) cout<<a[i] - 1<<' ';
    cout<<(1 << c)<<'\n';
    cout<<flush;
    int x; cin>>x;
    ans.push_front(++x);
    for(int i = 0;i<a.size();++i) if(a[i] != x) {
        cout<<"? "<<x - 1<<' '<<a[i] - 1<<'\n'<<flush;
        int tmp; cin>>tmp;
        if(tmp) b.push_back(a[i]);
    }
    a.clear();
    for(auto x : b) a.push_back(x);
    b.clear();
    n = a.size();
    get();
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>n;
    for(int i = 1;i<=n;++i) a.push_back(i);
    get();
    cout<<"! "<<ans.size() - 1<<' ';
    for(int i = 0;i<ans.size();++i) cout<<ans[i] - 1<<" \n"[i==ans.size() - 1];
    cout<<flush;
    return 0;
}
