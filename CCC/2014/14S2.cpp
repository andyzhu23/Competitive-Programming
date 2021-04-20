#include <iostream>
#include <unordered_map>
#define endl "\n"
using namespace std;
const int N = 31;
unordered_map<string, string> Map;
int n;
string a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
        if(Map[a[i]].empty()){
            cin>>Map[a[i]];
            if(Map[a[i]] == a[i]) {
                cout<<"bad"<<endl;
                return 0;
            } else if(!Map[Map[a[i]]].empty() && Map[Map[a[i]]] != a[i]){
                cout<<"bad"<<endl;
                return 0;
            }
        } else {
            cout<<"bad"<<endl;
            return 0;
        }
    }
    cout<<"good"<<endl;
    return 0;
}
