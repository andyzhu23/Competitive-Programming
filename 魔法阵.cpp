/*
 * we can calculate that the whole length possible is at least greater than 9*t let t be the distance between c and d.
 * First we enumerate t, then we enumerate possibilities of C D and A B separately. 
 * When we are calculating C D, we can use dynamic programming to calculate all the possibilities possible for A and B
 * we use sum to store the number of possibilities, and the new sum is equal to the old sum adding the minimum possible
 * length which is 9 * t - 1. we can calculate the possibilities for the minimum length by multiplying number of A 
 * and number of B. Same thing when we enumerate A B. Therefore obtaining the answer
 * 
 * 
 * tips: use scanf and printf, use int x to read input instead of just straight away use the array a[i]
 * 
 */



#include <cstdio>
#define N (const int)(5e6 + 10)
#define sf scanf
#define pf printf
using namespace std;
int n, m;
int a[N];
int cnt[N], ans[N][5];

int main(){
    sf("%d %d",&n,&m);
    for(int i = 1;i<=m;i++){
        int x;
        sf("%d",&x);
        a[i] = x;
        cnt[a[i]]++;
    }

    for(int t = 1;t * 9 < n;t++){
        int sum = 0;
        for(int D = 9 * t + 2; D <=n;D++){
            int C = D - t;
            int A = D - 9 * t - 1;
            int B = A + 2 * t;
            sum += cnt[A] * cnt[B];
            ans[C][3] += sum * cnt[D];
            ans[D][4] += sum * cnt[C];
        }
        sum = 0;
        for(int A = n - 9 * t - 1; A >= 1; A--){
            int B = A + 2 * t;
            int D = A + 9 * t + 1;
            int C = D - t;
            sum += cnt[C] * cnt[D];
            ans[A][1] += sum * cnt[B];
            ans[B][2] += sum * cnt[A];
        }
    }

    for(int i = 1;i<=m;i++){
        pf("%d %d %d %d\n", ans[a[i]][1], ans[a[i]][2], ans[a[i]][3], ans[a[i]][4]);
    }
    return 0;
}
