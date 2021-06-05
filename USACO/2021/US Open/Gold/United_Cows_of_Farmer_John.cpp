#include <iostream>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#define endl "\n"
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, b[N];
map<int, int> pos; // previous position of b[i]
unordered_set<int> cnt; // whether one value appeared before
vector<int> pos2;
int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ll prev = ans;
        if(pos[b[i]] == 0) ans += cnt.size() - cnt.count(b[i]);
        else {
            vector<int> :: iterator it;
            it = lower_bound(pos2.begin(), pos2.end(), pos[b[i]]);

            ans += pos2.size() - (it - pos2.begin() + 1);
            if(!pos2.empty())
                pos2.erase(it);
        }
        //cout<<ans - prev<<endl;
        cnt.insert(b[i]);
        pos[b[i]] = i;
        pos2.push_back(i);
    }
    cout<<ans<<endl;
    return 0;
}
