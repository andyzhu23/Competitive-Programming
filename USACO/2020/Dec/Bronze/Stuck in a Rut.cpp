/*
 * This question's complete mark is very similar to the partial mark. For the partial mark, we just use bfs and
 * make each point traverse one by one one step at a time. However, to get complete mark, we need to add a discretization.
 * We only really need to care about the axis that actually contains some points. Therefore, we get rid of all the
 * other points using discretization to traverse only the axis that contain cows. However, when we enumerate the points,
 * we cannot just simply enumerate them in any order, as their length of going to the next axis is not the same. Therefore,
 * we have to constantly store the time it takes to go from the starting position to the next position after the current
 * position, and use a priority queue to sort the cows based on this value. This is the value nxt in my program. And
 * guess what, nxt is exactly the answer that we need! When traversing, we have to be careful of a few things. If
 * the cow moves out of totx or toty, then we know that the cow definitely will not touch other cows. Also, we need
 * to use a Map two d array as like a visit array to track which cell the cow had went through. If the next cell already
 * is occupied, it depends on the time that the last cow arrived, only when the next arrival time is greater or equal
 * than the current cow, we proceed. Finally, we initialize all cells with an arrival time of INF so that it will definitely
 * be greater once some cow first arrives
 */


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9;
int n, getX[N], getY[N], totx, toty, Map[N][N], ans[N];
unordered_map<int, int> MapX, MapY;
struct input {
    int id, x, y;
    char c;
}inputs[N];

struct cow {
    int x, y, nxt, id;
    char c;
    cow(int X, int Y, int NXT, int ID, char C){
        c = C;
        id = ID;
        y = Y;
        x = X;
        nxt = NXT;
    }

};

struct cmp{
    bool operator () (cow a, cow b){
        return a.nxt > b.nxt;
    }
};

priority_queue<cow, vector<cow>, cmp> heap;

inline bool cmp1(input a, input b) {
    return a.x < b.x;
}

inline bool cmp2(input a, input b) {
    return a.y < b.y;
}

inline bool cmp3(input a, input b) {
    return a.id < b.id;
}

inline void discretiztion(){
    sort(inputs + 1, inputs + n + 1, cmp1);
    for(int i = 1;i<=n + 1;i++){ // n + 1 because we also need to account the nth one
        if(MapX[inputs[i].x] == 0){
            MapX[inputs[i].x] = ++totx;
            getX[totx] = inputs[i].x;
        }
    }
    sort(inputs + 1, inputs + n + 1, cmp2);
    for(int i = 1;i<=n + 1;i++){ // n + 1 because we also need to account the nth one
        if(MapY[inputs[i].y] == 0){
            MapY[inputs[i].y] = ++toty;
            getY[toty] = inputs[i].y;
        }
    }
}

inline void initialization(){
    sort(inputs + 1, inputs + n + 1, cmp3);

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            Map[i][j] = INF;
        }
    }
    for(int i = 1;i<=n;i++){
        int idx = MapX[inputs[i].x];
        int idy = MapY[inputs[i].y];
        Map[idx][idy] = 0;
        if(inputs[i].c == 'E'){
            if(idx + 1 == totx) ans[i] = -1;
            else heap.push(cow(idx + 1, idy, getX[idx + 1] - getX[idx], inputs[i].id, inputs[i].c));
        } else if(inputs[i].c == 'N') {
            if(idy + 1 == toty) ans[i] = -1;
            else heap.push(cow(idx, idy + 1, getY[idy + 1] - getY[idy], inputs[i].id, inputs[i].c));
        }
    }
}

inline void simulate(){
    while(!heap.empty()){
        cow cur = heap.top(); heap.pop();
        if(cur.c == 'E'){
            if(Map[cur.x][cur.y] >= cur.nxt && cur.x + 1 <= totx){
                Map[cur.x][cur.y] = cur.nxt;
                cur.x ++;
                cur.nxt += getX[cur.x] - getX[cur.x - 1];
                heap.push(cur);
            } else {
                ans[cur.id] = cur.nxt;
                if(cur.x + 1 > totx) ans[cur.id] = -1;
            }
        } else {
            if(Map[cur.x][cur.y] >= cur.nxt && cur.y + 1 <= toty){
                Map[cur.x][cur.y] = cur.nxt;
                cur.y ++;
                cur.nxt += getY[cur.y] - getY[cur.y - 1];
                heap.push(cur);
            } else {
                ans[cur.id] = cur.nxt;
                if(cur.y + 1 > toty) ans[cur.id] = -1;
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    inputs[n + 1].x = inputs[n + 1].y = INF;
    inputs[n + 1].id = n + 1;
    for(int i = 1;i<=n;i++){
        char c;
        int x, y;
        scanf(" %c %d %d", &c, &x, &y);
        inputs[i].x = x;
        inputs[i].y = y;
        inputs[i].c = c;
        inputs[i].id = i;
    }
    discretiztion();
    initialization();
    simulate();
    for(int i = 1;i<=n;i++){
        if(ans[i] == -1) printf("Infinity\n");
        else printf("%d\n", ans[i]);
    }
    return 0;
}
