#include <bits/stdc++.h>
using namespace std;
template <typename T> using pq = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T> >;
pq<int> fir;
pqg<int> sec;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--) {
        string s; cin>>s;
        if(s == "query") {
            if(fir.empty()) cout<<"empty"<<'\n';
            else cout<<fir.top()<<'\n';
        }
        else {
            int x; cin>>x;
            if(fir.empty()) fir.push(x);
            else if(x > fir.top()) {
                sec.push(x);
                if(sec.size() > fir.size()) {
                    fir.push(sec.top());
                    sec.pop();
                }

            }
            else {
                fir.push(x);
                if(fir.size() > sec.size() + 1) {
                    sec.push(fir.top());
                    fir.pop();
                }
            }
        }
    }
    return 0;
}
