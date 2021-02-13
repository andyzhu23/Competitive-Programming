#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+36;
bool pho[N];
vector<int> Map[N];
int n,m,a,b,ans;
bool mark[N];
bool vis[N];
bool vis2[N];
int start;
int longest;
int longestDepth;
int dfs1(int pos, int depth){ // 标记出一定需要经过的几个点
    if(pho[pos]){
        mark[pos] = true;
        if(depth > longestDepth){
            start = pos; // 标记下一个dfs的起点，不管这个dfs从哪里开始永远把离他最远的pho点标记
            depth = longestDepth;
        }

    }
    for(int i = 0;i<Map[pos].size();i++){
        if(vis[Map[pos][i]]) continue;
        vis[Map[pos][i]] = true;
        dfs1(Map[pos][i], depth + 1);
        if(mark[Map[pos][i]]){
            mark[pos] = true;
        }
    }
    return 0;
}

int dfs2(int pos,int depth){ // 找出从起点到所有第一个dfs标记过的点并且回到原点所需要的时间
    longest = max(longest, depth); // 找出离起点最远的pho点，保证一定是所有两pho点之间最长距离
    for(int i = 0;i<Map[pos].size();i++){
        if(mark[Map[pos][i]] && !vis2[Map[pos][i]]){
            ans++;
            vis2[Map[pos][i]] = true;
            dfs2(Map[pos][i],depth+1);
            ans++;
        }
    }
    return 0;
}

int ai;
int main() {
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>ai;
        pho[ai] = true;
    }
    for(int i = 1;i<n;i++){
        cin>>a>>b;
        Map[a].push_back(b);
        Map[b].push_back(a);
    }
    vis[ai] = true;
    dfs1(ai, 0);
    ans = 0;
    vis2[start] = true;
    dfs2(start,0);
    cout<<ans - longest; // 答案为从起点遍历所有点且返回的时间减去两pho点之间最长距离。
    // 因为该题不要求回到起点，所以减去两pho点的最长距离就是最短时间
    return 0;
}