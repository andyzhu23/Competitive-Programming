/*
 * for this question, during the contest, I did a two dimensional prefix sum and enumerated two of the points.
 * therefore getting the answer. the time complexity is O(n^4). I only got 5/10.
 *
 * The actually way of solving this question is to enumerate every two rows, and try to find how many columns.
 * Ironically, this question was quite similar to the second question on the december silver contest, and I
 * still didn't get it right :-(.
 *
 * Basically all you do is you enumerate the two columns, after that, you want to find the first right point and
 * the first left point that is not ok to have in the sense that they contain numbers smaller than 100. We can get
 * that by using monotone stack, which can give us the answer in O(n) using stack. Note that we may over count
 * when two 100 are associated in the same region. We can easily avoid that by enumerating the right endpoint the
 * same way we do, but when we enumerate the left point, we need to pop the stack when we see 100 as well.
 */


#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
const int N = 555;
typedef stack<int> STK;
typedef long long ll;
STK stk;
int n, a[N][N], l[N], r[N];
bool ok[N]; // column doesn't contain numbers smaller than 100
bool hun[N]; // column contain 100

signed main(){
    scanf("%d",&n);
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            scanf("%d",&a[i][j]); // -1 is smaller, 1 is equal, 2 is greater
            if(a[i][j] == 100){
                a[i][j] = 1;
            } else if(a[i][j] > 100){
                a[i][j] = 2;
            } else a[i][j] = -1;
        }
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        //reinitialize every array
        memset(ok, true, N);
        memset(hun, false, N);
        memset(l, 0, N);
        memset(r, 0, N);
        for(int j = i;j<=n;j++){
            //initializing every array by using the result last time and add the result on the current row
            for(int k = 1;k<=n;k++){
                l[k] = 0;
                r[k] = 0;
                if(a[j][k] == -1) ok[k] = false;
                else if(a[j][k] == 1 && ok[k]){
                    hun[k] = true;
                }
            }
            // find the left point at most one of the 100 can go
            for(int k = 1;k<=n + 1;k++){
                if(!ok[k] || k == n + 1){
                    while(!stk.empty()){
                        int cur = stk.top(); stk.pop();
                        r[cur] = k;
                    }
                }
                if(hun[k]) stk.push(k);
            }
            // find the right point at most one of the 100 can go
            for(int k = n;k>=0;k--){
                if(!ok[k] || hun[k] || k == 0){
                    while(!stk.empty()){
                        int cur = stk.top(); stk.pop();
                        l[cur] = k;
                        // got TLE for calculating the answers after, so I calculated them here
                        // all the possible length you can choose on the left multiply by the right
                        ans += (cur - l[cur]) * 1ll * (r[cur] - cur) * 1ll;
                    }
                }
                if(hun[k]) stk.push(k);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
