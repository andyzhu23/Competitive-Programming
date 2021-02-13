#include <cstdio>
using namespace std;
const int N = 1e5+45;
int n,q,a,b;

struct cows{
    int x = 0;
    int y = 0;
    int z = 0;
}cows[N];

int main() {
    scanf("%d %d",&n,&q);
    for(int i =1;i<=n;i++){
        scanf("%d",&a);
        cows[i].x = cows[i-1].x;
        cows[i].y = cows[i-1].y;
        cows[i].z = cows[i-1].z;
        if(a == 1) cows[i].x++;
        else if(a == 2) cows[i].y++;
        else cows[i].z++;
    }
    while(q--){
        scanf("%d %d",&a,&b);
        printf("%d %d %d\n",cows[b].x - cows[a-1].x, cows[b].y - cows[a-1].y, cows[b].z - cows[a-1].z);
    }
    return 0;
}
