#include <bits/stdc++.h>
using namespace std;

#define pb push_back
template<typename T> using vec = vector<T>;
using vi = vec<int>;

const int N = 1e6 + 10;

template<typename T> struct Stack {
    T a[N];
    int tot = 0;
    void push(T x) {a[++tot] = x;}
    T pop() {return a[tot--];} 
    T top() {return a[tot];}
    T get(int pos) {return tot >= pos ? a[tot - pos + 1] : -1;};
    bool empty() {return tot == 0;}
};

Stack<int> stk, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vi h(n + 1), j(n + 1);
    for(int i = 1;i<=n;i++) cin>>h[i];
    for(int i = 1;i<=n;i++) cin>>j[i];
    for(int i = n;i>0;i--) {
        while(!stk.empty() && stk.top() <= h[i]) stk.pop();
        ans.push(stk.get(j[i]));
        stk.push(h[i]);
    }
    while(!ans.empty()) cout<<ans.pop()<<" ";
    cout<<"\n";
    return 0;
}
