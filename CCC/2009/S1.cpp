#include <bits/stdc++.h>

using namespace std;
int a,b,ans;

int main() {
    cin>>a>>b;
    ans = 0;
    for(int i=0; i<100; i++)
    {
        if(pow(i,6)>=a and pow(i,6)<=b)
        {
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
