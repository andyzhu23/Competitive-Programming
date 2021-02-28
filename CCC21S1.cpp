/*
 * This question is a TROLL!!!!!!!!!!!!!!!!!!!!
 * do not store the answer using double. Double will store the answer in scientific notation once
 * the answer is big, giving you wrong answer and make you question your intelligence
 */

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], b[N];

signed main() {
    cin>>n;
    for(int i = 1;i <= n + 1;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        ans += b[i] * (a[i] + a[i + 1]);
    }
    if(ans % 2 == 0) cout<<ans / 2<<endl;
    else cout<<ans / 2<<".5"<<endl;
    return 0;
}
