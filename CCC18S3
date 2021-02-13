#include <iostream>
#include <vector>
#include <queue>
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
queue<pos> q;

bool isOk(int a, int b){
    return (a>=0 && n>a) && (b>=0 && m>b);
}

bool check(int a, int b)
{
  if(isOk(a,b) == false) return false;
  if(vis[a][b] == 1) return false;
  if(Map[a][b] == 'W' || Map[a][b] == 'C') return false;
  return true;
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

void print()
{
  cout << "####### vis #########\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++){
      cout << vis[i][j] << " ";
    } 
    cout << endl;
  }
}

int main() {
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>Map[i];
        for(int j = 0;j<m;j++){
            if(Map[i][j] == 'C') c.push_back(make_pair(i,j));
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
    vis[cur.a][cur.b] = 1;
    if(Map[cur.a][cur.b] != 'C') q.push(cur);
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(Map[cur.a][cur.b] == '.'){
            ans[cur.a][cur.b] = cur.step;
        }
        for(int i = 0;i<4;i++){
            pos nxt;
            nxt.a = cur.a+dir[i][0];
            nxt.b = cur.b+dir[i][1];
            nxt.step = cur.step+1;
            
            if(check(nxt.a, nxt.b) == false) continue;
            vis[nxt.a][nxt.b] = 1;
            
            int flag = 1;
            while(flag)
            {
              flag = 0;
              if(Map[nxt.a][nxt.b] == 'L'){
                  nxt.b--;
                  flag = 1;
              } else if(Map[nxt.a][nxt.b] == 'R'){
                  nxt.b++;
                  flag = 1;
              } else if(Map[nxt.a][nxt.b] == 'U'){
                  nxt.a--;
                  flag = 1;
              } else if(Map[nxt.a][nxt.b] == 'D'){
                  nxt.a++;
                  flag = 1;
              } 
              if(flag == 1 && check(nxt.a, nxt.b) == false) {
                flag = 2;
                break;
              }
              vis[nxt.a][nxt.b] = 1;
              if(Map[nxt.a][nxt.b] == '.') break;
            }
            if(flag != 2)q.push(nxt);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(ans[i][j] != 0) cout<<ans[i][j]<<"\n";
        }
    }
    return 0;
}
