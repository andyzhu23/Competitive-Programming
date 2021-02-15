#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> p;
struct cor{
 int first, second, dep;
};
const int N =1e2;

string Map[N];

int t, r, c;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool isOk(cor next){
    int x = next.first;
    int y = next.second;
    if(x < 1 || x > r || y < 1 || y > c || Map[x][y] == '*') return false;
    return true;
}

int bfs(){
    queue<cor> q;
    set<p> vis;
    cor cur;
    cur.first = 1;
    cur.second = 1;
    cur.dep = 1;
    q.push(cur);
    while(!q.empty()){
        cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        int dep = cur.dep;
        p coor = make_pair(x,y);
        if(vis.count(coor)) continue;
        vis.insert(coor);
        if(x == r && y == c){
            return dep;
        }
        cor next;
        if(Map[x][y] == '+'){
            for(int i = 0;i<4;i++){
                int nX = x + dir[i][0];
                int nY = y + dir[i][1];
                next.first = nX;
                next.second = nY;
                next.dep = dep + 1;
                if(isOk(next)) q.push(next);
            }
        } else if(Map[x][y] == '-'){
            for(int i = 0;i<2;i++){
                int nX = x + dir[i][0];
                int nY = y + dir[i][1];
                next.first = nX;
                next.second = nY;
                next.dep = dep + 1;
                if(isOk(next)) q.push(next);
            }
        } else if(Map[x][y] == '|'){
            for(int i = 2;i<4;i++){
                int nX = x + dir[i][0];
                int nY = y + dir[i][1];
                next.first = nX;
                next.second = nY;
                next.dep = dep + 1;
                if(isOk(next)) q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    cin>>t;
    while(t--){
        cin>>r>>c;
        for(int i = 1;i<=r;i++){
            cin>>Map[i];
            Map[i] = '@' + Map[i];
        }
        int ans = bfs();
        cout<<ans<<endl;
    }
    return 0;
}
