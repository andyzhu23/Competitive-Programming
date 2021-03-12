/*
 * for this question, we need to use prefix-sum or in this case suffix-sum as well to calculate. We need a prefix-sum
 * to indicate the shortest number of brushes to brush the fences from 1 to a - 1, and a suffix-sum to indicate
 * the shortest number of brushes to brush the fences from n to b + 1. If we analyze it, it is not difficult to
 * understand that if a[i] and a[i - 1] is the same, then we only need as many brushes as the one before. if
 * a[i] > a[i - 1], then it is obvious that we definitely need one more brush to get the job done. The only case we have
 * left is when a[i] > a[i - 1]. To solve this case, all we need is an array to store the last appearance of a
 * certain letter. Once we know a[i] > a[i - 1], we can start to enumerate the last appearance of all j for
 * j < i. If any j is in between the current a[i] and the last a[i], then we need one more brush, else we don't. 
 * Then we just update this array once we done the calculation
 */



#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
int n, Q, a[N];
int prefix[N], suffix[N];
int prevPos[N];

int main(){
    scanf("%d %d",&n,&Q);
    for(int i = 1;i<=n;i++){
        char c; cin>>c;
        a[i] = c - 'A' + 1;
    }
    for(int i = 1;i<=26;i++) prevPos[i] = -1;
    // prefix sum
    for(int i = 1;i<=n;i++){
        if(a[i] > a[i - 1] || prevPos[a[i]] == -1) prefix[i] = prefix[i - 1] + 1;
        else if(a[i] == a[i - 1]) prefix[i] = prefix[i - 1];
        else {
            for(int j = 1;j<a[i]; j ++){
                // make sure that it is prevPos[j] not prevPos[a[j]]
                if(prevPos[j] > prevPos[a[i]]) {
                    prefix[i] = prefix[i - 1] + 1;
                    break;
                }
            }
            if(prefix[i] != prefix[i - 1] + 1){
                prefix[i] = prefix[i - 1];
            }
        }
        prevPos[a[i]] = i;//update prevPos
    }
    //suffix sum
    for(int i = 1;i<=26;i++) prevPos[i] = n + 1;
    for(int i = n;i>0;i--){
        if(a[i] > a[i + 1] || prevPos[a[i]] == n + 1) suffix[i] = suffix[i + 1] + 1;
        else if(a[i] == a[i + 1]) suffix[i] = suffix[i + 1];
        else {
            for(int j = 1;j<a[i]; j++){
                // make sure that it is prevPos[j] not prevPos[a[j]]
                if(prevPos[j] < prevPos[a[i]]){
                    suffix[i] = suffix[i + 1] + 1;
                    break;
                }
            }
            if(suffix[i] != suffix[i + 1] + 1){
                suffix[i] = suffix[i + 1];
            }
        }
        prevPos[a[i]] = i;//update prevPos
    }
    while(Q--){
        int A, B;
        scanf("%d %d",&A,&B);
        printf("%d\n",prefix[A - 1] + suffix[B + 1]);
    }

    return 0;
}
