#include <iostream>
#include <cstdio>
using namespace std;

int n;

typedef pair<int, int> p;

p findFactor(int x){
    int y = x / 2;
    while((x - y) % y != 0){
        y--;
    }
    return make_pair(y, x - y);
}

int main() {
    scanf("%d",&n);
    int ans = 0;
    while(n > 1){
        if(n%2 == 0){
            n = n / 2;
            ans++;
        } else {
            p fac = findFactor(n);
            ans += fac.second / fac.first;
            n = fac.second;
        }
    }
    printf("%d", ans);
    return 0;
}
