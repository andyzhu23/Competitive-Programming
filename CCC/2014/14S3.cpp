#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int t, n, a,b[N];
stack<int> stk;


int main() {
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> ans;
        int need = 1;
        for(int i = n;i>=1;i--){
            cin>>b[i];
        }
        for(int i = 1;i<=n;i++){
            a = b[i];
            bool take = false;
            if(a == need){
                ans.push_back(a);
                need ++;
                take = true;
            }
            while(!stk.empty()){
                if(stk.top() == need) {
                    ans.push_back(stk.top()); stk.pop();
                    need ++;
                } else {break;}
            }
            if(!take) stk.push(a);
        }

        if(ans.size() >= n) cout<<"Y\n";
        else cout<<"N\n";
    }
    return 0;
}
