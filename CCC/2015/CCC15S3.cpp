#include <iostream>
#include <vector>
using namespace std;

vector<int> fre;

int g, p;

int binarySearch(int x){
    int ans = -1, l = 0, r = fre.size() - 1, mid;
    while(l<=r){
        mid = (l + r) / 2;
        if(fre[mid] == x) return mid;
        else if(fre[mid] < x){
            ans = mid;
            l = mid +1;
        } else r = mid - 1;
    }
    return ans;
}

int main() {
    cin>>g>>p;
    int ans = 0;
    for(int i = 1;i<=g;i++){
        fre.push_back(i);
    }
    int a;
    for(int i = 1;i<=p;i++){
        cin>>a;
        int k = binarySearch(a);
        if(k == -1){
            cout<<ans<<endl;
            return 0;
        } else {
            fre.erase(fre.begin() + k);
            ans ++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
