#include <iostream>
#include <vector>
#include <deque>
using namespace std;
const int N = 120;
typedef pair <int, int> cor;
struct pos{
    int a,b,step;
};
string Map[N];
vector<cor> c;
cor start;
int ans[N][N];
bool vis[N][N];
int n,m;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
deque<pos> q;

bool isOk(int a, int b){
    return (a>=0 && n>a) && (b>=0 && m>b);
}

void updateCamera(){
    int a,b;
    for(int i = 0;i<c.size();i++){
        for(int j = 0;j<4;j++){
            a = c[i].first;
            b = c[i].second;
            while(isOk(a,b)){
                a += dir[j][0];
                b += dir[j][1];
                if(Map[a][b] == 'W') break;
                else if(Map[a][b] == '.' || Map[a][b] == 'S') Map[a][b] = 'C';
            }
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>Map[i];
        for(int j = 0;j<m;j++){
            if(Map[i][j] == 'C') c.emplace_back(make_pair(i,j));
            else if(Map[i][j] == 'S'){
                start.first = i;
                start.second = j;
            } else if(Map[i][j] == '.'){
                ans[i][j] = -1;
            }
        }
    }
    updateCamera();
    pos cur;
    cur.a = start.first;
    cur.b = start.second;
    cur.step = 0;
    if(Map[cur.a][cur.b] != 'C') q.push_back(cur);
    int a,b,step;
    while(!q.empty()){
        cur = q.front(); q.pop_front();
        a = cur.a;
        b = cur.b;
        vis[a][b] = true;
        step = cur.step;
        if(Map[a][b] == '.'){
            ans[a][b] = step;
        }
        if(Map[a][b] == 'W' || Map[a][b] == 'C') continue;
        else if(Map[a][b] == 'L'){
            cur.b--;
            if(!vis[cur.a][cur.b]) q.push_front(cur);
        } else if(Map[a][b] == 'R'){
            cur.b++;
            if(!vis[cur.a][cur.b]) q.push_front(cur);
        } else if(Map[a][b] == 'U'){
            cur.a--;
            if(!vis[cur.a][cur.b]) q.push_front(cur);
        } else if(Map[a][b] == 'D'){
            cur.a++;
            if(!vis[cur.a][cur.b]) q.push_front(cur);
        } else{
            for(int i = 0;i<4;i++){
                pos next;
                next.a = a+dir[i][0];
                next.b = b+dir[i][1];
                next.step = cur.step+1;
                if(isOk(next.a,next.b) && !vis[next.a][next.b]) q.push_back(next);
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(ans[i][j] != 0) cout<<ans[i][j]<<"\n";
        }
    }
    return 0;
}
