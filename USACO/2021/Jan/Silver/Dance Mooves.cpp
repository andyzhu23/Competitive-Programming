/*
 * For this question, there are a set of steps that we need to take in order to reach the final answer. First, we need to 
 * compute the K turns once. The reason why we are doing it is because after we did it, we can easily identify the self loops.
 * If a cow at position 1 that end up in position 4, it is going to travel through the exact same positions as cow 4 did.
 * Once we get that, the next step is to run a dfs and run through all those self loops. As we go to those self loops, we can
 * easily store all the different positions that each cow went through. I used an unordered_set, which is going to avoid any
 * duplicates, but there are also lots of other ways out there. Once we did that, we also need to store all the cows within
 * this self loop so that when we enumerate to that cow, we don't have to run the whole same dfs again. After that we store 
 * everything in the answer array and clear the unordered_set ready for its next use. Then all that we have to do is
 * to just print out the answers.
 */


#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef queue<int> qi;
typedef unordered_set<int> usi;
const int N = 1e6 + 10;
vi pos[N]; // store all the positions that every cow went through in one rotation
qi q; // store all the cows in a self loop
usi node; // store all the nodes in a self loop
int a[N], b[N], n, k;
int cow[N], vis[N], ans[N];

void dfs(int u) {
    q.push(u);
    vis[u] = true;
    int len = pos[u].size() - 1;
    for (int x: pos[u])
        node.insert(x);
    int v = pos[u][len];
    if(!vis[v]){
        dfs(v);
    }
}

int main() {
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++){
        cow[i] = i;
        pos[cow[i]].pb(i);
    }
    for(int i =1;i<=k;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    // simulate the cow's rotation
    for(int i = 1;i<=k;i++){
        int tmp = cow[a[i]];
        pos[cow[a[i]]].pb(b[i]);
        cow[a[i]] = cow[b[i]];
        pos[cow[b[i]]].pb(a[i]);
        cow[b[i]] = tmp;
    }
    // enumerate every cow and get the answers
    for(int i = 1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans[cur] = node.size();
        }
        node.clear();
    }
    for(int i = 1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
