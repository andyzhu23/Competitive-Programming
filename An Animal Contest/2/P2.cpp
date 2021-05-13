/*
 * Author: Andy Zhu
 *
 * just a noob, what is coding?
 *
 * “Do we run the trails, or the trails run us? Get revenge on the trails that ran u like that”
 * I pray the cows
 * My Dream School:
 * South Harmon Institute of Technology
 * The meaning of life is:
 * #define int long long
 */

#include <iostream>
#include <fstream>

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <algorithm>
#include <iterator>
#include <deque>
#define endl "\n"

#define log(a, b) log(a) / log(b)

using namespace std;

typedef unordered_map<int, int> UMI;

const int INF = 1e9;

const int N = 4e3 + 10;
int n;
int a[N];
unordered_set<int> vis;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        vis.insert(a[i]);
    }
    sort(a + 1, a + n + 1);
    if(n == 1){
        cout<<1<<endl;
        return 0;
    }
    if(n == 2){
        if(a[1] % 2 == a[2] % 2) cout<<2<<endl;
        else cout<<1<<endl;
        return 0;
    }
    int Max = a[n];
    for(int i = 1;i<n;i++){
        for(int j = i + 1;j<=n;j++){
            int cur = (a[j] << 1) - a[i];
            if(cur > Max) break;
            if(vis.count(cur)) {
                cout<<3<<endl;
                return 0;
            }
        }
    }
    cout<<2<<endl;
    return 0;
}
