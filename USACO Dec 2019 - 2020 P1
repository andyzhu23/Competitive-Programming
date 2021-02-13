#include <iostream>
using namespace std;
const long long N = 1e10+4;
long long n;
long long getNum(long long x){
    return x-x/3 -x/5+x/15;
}

long long isOk(int num){
    if(num%5 == 0||num%3==0||num%15 ==0) return false;
    return true;
}
int main() {
    cin>>n;
    long long l = 1,r = N,mid;
    while(r>=l){
        mid = (r + l)/2;
        long long num = getNum(mid);
        if(num == n){
            while(true) {
                if(isOk(mid)){
                    cout<<mid;
                    return 0;
                }
                mid--;
            }
        } else if(num>n){
            r = mid-1;
        } else if(num<n){
            l = mid+1;
        }
    }
    return 0;
}
