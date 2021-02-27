#include <iostream>
#include <queue>
#define p pair<int, int>
#define f first
#define s second
#define mp make_pair
using namespace std;
const int sz = 3e3 + 10;
int grid[sz][sz], n;
bool vis[sz][sz];
bool added[sz][sz];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<p> q;// store comfortable cows

void updateCow(int a, int b){
    vis[a][b] = true;
    for(int j = 0;j<4;j++){
        // c and d is the pos of the next cow
        int c = a + dir[j][0];
        int d = b + dir[j][1];
        if(vis[c][d]){
            grid[a][b]++;
            grid[c][d]++;
            if(grid[a][b] == 3) q.push(mp(a,b));
            if(grid[c][d] == 3) q.push(mp(c,d));
        }
    }
}

int main() {
    cin>>n;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        int a, b;

        cin>>a>>b;
        // a and b is the pos of the current cow
        a+= 1000;
        b+= 1000;
        if(added[a][b]){
            added[a][b] = false;
            ans--;
            cout<<ans<<endl;
            continue;
        }
        updateCow(a, b);
        // find cows need to be added
        // if a cow is comfortable it will be pushed into the q until the q is empty
        while(!q.empty()){
            p cur = q.front(); q.pop();

            for(int j = 0;j<4;j++){
                int c = cur.f + dir[j][0];
                int d = cur.s + dir[j][1];
                if(!vis[c][d]){
                    updateCow(c, d);
                    added[c][d] = true;
                    ans++;
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
