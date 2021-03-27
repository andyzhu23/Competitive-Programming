/*
 * let all the other be 1 and only consider the last three. If the remaining number is even, then just make the 
 * last two numbers half the remain. If the remaining number is odd, then you let another number be 2 and make them be
 * half the amount. Note that if half the remain is odd, then the LCM will be half the remain multiply by 2 which might
 * be bigger than n/2. Therefore, if half the remain is odd, then consider making the last three numbers half the remain, 
 * and the other two half of the half of the remain.
 */

#include <iostream>
using namespace std;
int n, k, a[10];
void solve(){
    scanf("%d %d", &n, &k);
    a[1] = a[2] = a[3] = 1;
    int left = n - k;
    if(left % 2 == 0){
        a[2] += left / 2;
        a[3] += left / 2;
    } else if((left + 2) / 2 % 2 == 0){
        a[1] ++;
        a[2] += left / 2;
        a[3] += left / 2;
    } else {
        left += 3;
        a[1] = left / 2;
        a[2] = a[3] = left / 4;
    }
    for(int i = 1;i<=k - 3;i++) printf("%d ", 1);
    for(int i = 1;i<=3;i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
