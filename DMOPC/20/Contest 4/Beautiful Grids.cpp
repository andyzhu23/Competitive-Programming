/*
 * for this question, the key idea is simple. You can safe up some flips if you flip a coin and make
 * the row and the column that it is in even. Therefore, we need to enumerate through all the rows and columns.
 * Note that it is possible that rows might still be odd even if all the columns are even or vise versa. In that case
 * just flip any point in the same row or column (I flipped the first one but any will work).
 * To solve this problem fully, all we need to do is to use a map or in my case I like to use unordered_map as the
 * time complexity on average will be O(1) will as a regular map is O(log n). Since we don't really need to worry about
 * rows and columns that are not flipped initially, we just need to store the rows and column somehow, and that is
 * why I choose unordered_set, which will safe all the rows and columns and automatically cancel out all the duplicates.
 * Upon having all this, just iterate through the unordered_set and it should be done.
 *
 * Note that it is very important to break out of the for loop enumerating the possible columns as not doing so will
 * only give you a valid sequence, but not the shortest. Another note is that if you do not save the position of the
 * last column you enumerate, it will start from the first one the second time. We know that any position from start
 * to the last column is guaranteed not going to have any odd ones because you already solved them before. Therefore,
 * safe up the position should drastically improve your time complexity from O(K ^ 2) to O(2K)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#define mp make_pair
#define f first
#define s second
#define push_back emplace_back
#define int long long
using namespace std;
typedef pair<int, int> p;
typedef unordered_set<int> usi;
typedef unordered_map<int, int> umi;
vector<p> res;
int n, m, k;
umi row, col;
usi vis1, vis2;
signed main() {
    cin>>n>>m>>k;
    // reading input
    for(int i = 1;i<=k;i++){
        int a, b; cin>>a>>b;
        row[a] ++;
        col[b] ++;
        // stores all the unique row and column to a unordered set
        vis1.insert(a);
        vis2.insert(b);
    }
    // enumerate every row and column to cancel out as many odd rows and columns as possible
    // same the position of the last column so we don't have to start from the beginning
    auto pos = vis2.begin();
    // enumerate all the unique rows and columns in vis1 and vis2
    for(auto it = vis1.begin(); it != vis1.end(); it++){
        int i = *it;
        if(row[i] % 2 == 0) continue;
        for(auto it2 = pos; it2 != vis2.end(); it2++){
            int j = *it2;
            if(row[i] % 2 == 0) break; // make sure to break out
            if(col[j] % 2 != 0){
                row[i] ++;
                col[j] ++;
                res.push_back(mp(i, j));
                pos = it2;
            }
        }
    }
    // if any rows still are odd, then just enumerate through and flip any at the same row if the row is odd
    for(auto it = vis1.begin(); it != vis1.end(); it++){
        int i = *it;
        if(row[i] % 2 == 1){
            row[i] ++;
            col[1] ++;
            res.push_back(mp(i, 1));
        }
    }
    // if any col still are odd, then just enumerate through and flip any at the same col if the col is odd
    for(auto it = vis2.begin(); it != vis2.end(); it++){
        int j = *it;
        if(col[j] %2 == 1){
            col[j] ++;
            row[1]++;
            res.push_back(mp(1, j));
        }
    }
    printf("%lld\n", (int)res.size());
    for(p i: res){
        printf("%lld %lld\n", i.f, i.s);
    }
    return 0;
}
