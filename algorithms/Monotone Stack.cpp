#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int n, a[N], ans[N];
stack<int> stk;

int main(){
  cin>>n;
  for(int i =1;i<=n;i++){
    cin>>a[i];
    
    while(!stk.empty() && a[stk.top()] < a[i]){
      ans[stk.top()] = i;
      stk.pop();
    }
    stk.push(i);
  }
  while(!stk.empty()){
		ans[stk.top()] = n + 1;
    stk.pop();
  }
  for(int i = 1;i<=n;i++) cout<<ans[i] <<" ";
  return 0;
}
