/*
 * this simulates a priority_queue
 */


#include <iostream>
#include <cstdio>
#include <utility>
#define int long long
using namespace std;
const int N = 1e7 + 10;
int n, heap[N], tot = 0;

void move_up(int p){
    if(p <= 1) return;
    if(heap[p] > heap[p / 2]){
        swap(heap[p], heap[p / 2]);
        move_up(p / 2);
    }
}

void heap_push(int x){
    heap[++tot] = x;
    move_up(tot);
}

void move_down(int p){
    int son = p * 2;
    if(son > tot) return;
    if(son + 1 <= tot && heap[son + 1] > heap[son]){
        son += 1;
    }
    if(heap[p] < heap[son]) {
        swap(heap[son], heap[p]);
        move_down(son);
    }
}

void heap_pop(){
    swap(heap[tot], heap[1]);
    tot--;
    move_down(1);
}

signed main() {
    scanf("%lld", &n);
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        if(s == "push"){
            int x;
            scanf("%lld", &x);
            heap_push(x);
        } else {
            if(tot <= 0) printf("empty\n");
            else{
                printf("%lld\n", heap[1]);
                heap_pop(); // make sure only pop when it is not empty
            }

        }
    }
    return 0;
}
