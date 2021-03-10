/*
 * so for this question, it may look like lots to consider, but really all you need is the minimum
 * distance from all the points to a. Now, when we calculate this, we want to know whether or not it is possible
 * for the signal kinda L to reach 1 from a. Then all we know is that the 1st person can just keep passing the 
 * signal with the 2nd person until the L becomes 0. However, two things we have to consider, if L becomes 1,
 * then the 2nd person will need to supply 0 which will give us a no answer. Now how do we know whether L will
 * become 1, or 0? As we are finding the shortest distance, we need to find two distance, the shortest odd distance,
 * and the shortest even distance. After we get these number, the next step is easy, if L is odd, then see if you can
 * reach 1 from a in odd number of steps, and vise versa. 
 * 
 * Tiny details like from 1 to 1 require zero steps need to be separatly calculated.
 */


#include <iostream>
#include <vector>
#include <queue>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int, int> PI;
typedef vector<int> VI;
typedef queue <PI> QI;
const int N =1e5 + 10;
QI q;
VI e[N];
int odd[N], even[N];
int n, m, Q;

void BFS(int start){
    q.push(mp(start, 0));
    while(!q.empty()){
        PI u = q.front(); q.pop();
        for(int v: e[u.f]){
            int w = u.s + 1;
            if(w % 2 == 1 && (odd[v] == 0)){
                odd[v] = w;
                q.push(mp(v, w));

            } else if (w % 2 == 0 && (even[v] == 0 && v != start)){
                even[v] = w;
                q.push(mp(v, w));
            }

        }
    }
}


int main(){
    cin>>n>>m>>Q;
    for(int i = 1;i<=m;i++){
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    BFS(1);
    while(Q--){
        int a, L;
        cin>>a>>L;
        if(L % 2 == 0 && even[a] <= L && (even[a] != 0 || a == 1) ) cout<<"Yes"<<endl;
        else if(L % 2 == 1 && odd[a] <= L && odd[a] != 0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
