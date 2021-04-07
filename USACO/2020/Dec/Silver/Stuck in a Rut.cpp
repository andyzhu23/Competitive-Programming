#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9;
int n, getX[N], getY[N], totx, toty, Map[N][N];
int ans[N], res[N], vis[N][N];
map<int, int> MapX, MapY;
struct input {
    int id, x, y;
    char c;
} inputs[N];

struct cow {
    int x, y, nxt, id;
    char c;

    cow(int X, int Y, int NXT, int ID, char C) {
        c = C;
        id = ID;
        y = Y;
        x = X;
        nxt = NXT;
    }

};

inline bool operator >(cow a, cow b){
    return a.nxt > b.nxt;
}


priority_queue<cow, vector<cow>, greater<cow>> heap;

inline bool cmp1(input a, input b) {
    return a.x < b.x;
}

inline bool cmp2(input a, input b) {
    return a.y < b.y;
}

inline bool cmp3(input a, input b) {
    return a.id < b.id;
}

inline void discretiztion() {
    sort(inputs + 1, inputs + n + 1, cmp1);
    for (int i = 1; i <= n + 1; i++) { // n + 1 because we also need to account the nth one
        if (MapX[inputs[i].x] == 0) {
            MapX[inputs[i].x] = ++totx;
            getX[totx] = inputs[i].x;
        }
    }
    sort(inputs + 1, inputs + n + 1, cmp2);
    for (int i = 1; i <= n + 1; i++) { // n + 1 because we also need to account the nth one
        if (MapY[inputs[i].y] == 0) {
            MapY[inputs[i].y] = ++toty;
            getY[toty] = inputs[i].y;
        }
    }
}

inline void initialization() {
    sort(inputs + 1, inputs + n + 1, cmp3);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            Map[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        int idx = MapX[inputs[i].x];
        int idy = MapY[inputs[i].y];
        Map[idx][idy] = 0;
        vis[idx][idy] = i;
        if (inputs[i].c == 'E') {
            if (idx + 1 == totx) ans[i] = -1;
            else heap.push(cow(idx + 1, idy, getX[idx + 1] - getX[idx], inputs[i].id, inputs[i].c));
        } else if (inputs[i].c == 'N') {
            if (idy + 1 == toty) ans[i] = -1;
            else heap.push(cow(idx, idy + 1, getY[idy + 1] - getY[idy], inputs[i].id, inputs[i].c));
        }
    }
}

inline void simulate() {
    while (!heap.empty()) {
        cow cur = heap.top();
        heap.pop();
        if (cur.c == 'E') {
            if (Map[cur.x][cur.y] >= cur.nxt && cur.x + 1 <= totx) {
                vis[cur.x][cur.y] = cur.id;
                Map[cur.x][cur.y] = cur.nxt;
                cur.x++;
                cur.nxt += getX[cur.x] - getX[cur.x - 1];
                heap.push(cur);
            } else if (Map[cur.x][cur.y] < cur.nxt) {
                ans[cur.id] = vis[cur.x][cur.y];
            } else if (cur.x + 1 > totx) ans[cur.id] = -1;
        } else {
            if (Map[cur.x][cur.y] >= cur.nxt && cur.y + 1 <= toty) {
                vis[cur.x][cur.y] = cur.id;
                Map[cur.x][cur.y] = cur.nxt;
                cur.y++;
                cur.nxt += getY[cur.y] - getY[cur.y - 1];
                heap.push(cur);
            } else if (Map[cur.x][cur.y] < cur.nxt) {
                ans[cur.id] = vis[cur.x][cur.y];
            } else if (cur.y + 1 > toty) ans[cur.id] = -1;
        }
    }
}

int in[N];
vector<int> v[N];
queue<int> q;

inline void getTopo() {
    for (int i = 1; i <= n; i++) {
        if(ans[i] == -1) continue;
        v[i].push_back(ans[i]);
        in[ans[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i: v[cur]) {
            in[i]--;
            res[i] += res[cur] + 1;
            if (in[i] == 0) {
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    inputs[n + 1].x = inputs[n + 1].y = INF;
    inputs[n + 1].id = n + 1;
    for (int i = 1; i <= n; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        inputs[i].x = x;
        inputs[i].y = y;
        inputs[i].c = c;
        inputs[i].id = i;
    }
    discretiztion();
    initialization();
    simulate();
    getTopo();
    for (int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }
    return 0;
}
