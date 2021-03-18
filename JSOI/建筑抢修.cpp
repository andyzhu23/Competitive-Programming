/*
 * This question is just like the classic greedy question where you play around with intervals of time. Except here,
 * you are free to perform a task anytime before its deadline. Therefore, what we need to do is to enumerate through 
 * all the chores in the sorted order of going from smallest to biggest by the finishing time. If you can complete the
 * task under the time frame, then you do the task, otherwise you will want to see if replacing with another task is better
 * Therefore, you choose to switch it with the task that take the longest time. How do we find the task in the longest time?
 * priority_queue
 */

#include <iostream>
#include <algorithm>
#include <queue>
#define f first
#define s second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
typedef priority_queue<p> pqi;
const int N = 2e6;
int n;
p build[N];
pqi heap;
bool cmp(p a, p b){
    return a.s < b.s;
}

int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        ll a, b;
        cin>>a>>b;
        build[i].f = a;
        build[i].s = b;
    }
    sort(build + 1, build + n + 1, cmp);
    ll cur = 0;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if(build[i].s - build[i].f >= cur){
            ans ++;
            cur += build[i].f;
            heap.push(build[i]);
        } else if(!heap.empty()){
            p chore = heap.top(); heap.pop();
            if(chore.f > build[i].f){
                cur = cur - chore.f + build[i].f;
                heap.push(build[i]);
            } else heap.push(chore);
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
4
100 200
200 1300
1000 1250
1299 3200
 */
