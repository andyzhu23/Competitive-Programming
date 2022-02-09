#include <bits/stdc++.h>
using namespace std;

const int N = 602;
const int way[9][3] = {
    {-1, 2, -1}, {2, -1, -1}, {-1, -1, 2}, 
    {-2, -2, 4}, {4, -2, -2}, {-2, 4, -2}, 
    {-3, 6, -3}, {6, -3, -3}, {-3, -3, 6}
};
int n, a, b, c;

int dist[N][N];

struct game {
    int a, b, c;
    bool operator<(const game& other) const {
        return dist[a][b] > dist[other.a][other.b];
    }
};
priority_queue<game> heap;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    heap.push({300, 300, 300});
    memset(dist, 0x3f, sizeof(dist));
    dist[300][300] = 0;
    while(!heap.empty()) {
        game u = heap.top(); heap.pop();
        for(auto x : way) {
            game nxt = u;
            nxt.a += x[0];
            nxt.b += x[1];
            nxt.c += x[2];
            if(max({nxt.a, nxt.b, nxt.c}) > 600 || min({nxt.a, nxt.b, nxt.c}) < 0) continue;
            if(dist[nxt.a][nxt.b] > dist[u.a][u.b] + 1) {
                dist[nxt.a][nxt.b] = dist[u.a][u.b] + 1;
                if(dist[nxt.a][nxt.b] < 100) heap.push(nxt);
            }
        }
        for(auto x : way) {
            game nxt = u;
            nxt.a -= x[0];
            nxt.b -= x[1];
            nxt.c -= x[2];
            if(max({nxt.a, nxt.b, nxt.c}) > 600 || min({nxt.a, nxt.b, nxt.c}) < 0) continue;
            if(dist[nxt.a][nxt.b] > dist[u.a][u.b] + 1) {
                dist[nxt.a][nxt.b] = dist[u.a][u.b] + 1;
                if(dist[nxt.a][nxt.b] < 100) heap.push(nxt);
            }
        }
    }
    dist[300][300] = 2;
    cin>>n>>a>>b>>c;
    cout<<(dist[a + 300][b + 300] > n ? -1 : dist[a + 300][b + 300])<<'\n';
    return 0;
}
