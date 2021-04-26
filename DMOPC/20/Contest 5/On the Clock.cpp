#include <iostream>
#define endl "\n"
#define int long long
using namespace std;
const int N = 1e7 + 10;
int n, m, ans[N][2];

inline int gcd(int a, int b){
    if(a == 0) return b;
    else if(b == 0) return a;
    return gcd(b, a % b);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int a = n / gcd(n, m);
    int b = m / gcd(n, m);
    double slope = double(b) / double(a);
    double l = 0;
    double r = 0;
    int L = 1;
    int R = 1;
    int cnt = 0;
    for(int i = 1;i<=a;i++){
        l = r;
        L = R;
        r += slope - (int)(slope);
        R += (int)(r);
        r = (r - (int)(r));

        R += (int)(slope);

        ans[i][0] = L;
        ans[i][1] = R + 1;
        if(i == a) ans[i][1] = b + 1;
        cnt += ans[i][1] - ans[i][0];
    }
    cnt *= gcd(n, m);
    cout<<cnt<<endl;
    for(int i = 1;i<=n;i++){
        int x = (i - 1) / a;
        for(int j = ans[i - x * a][0];j<ans[i - x * a][1];j++){
            cout<<i<< " " <<j + x * b<<endl;
        }
    }
    return 0;
}
