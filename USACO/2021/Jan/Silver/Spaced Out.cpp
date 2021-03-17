/*
 * for this question, we need to know that once we know what the first two lines look like, we can determine
 * the whole matrix. Therefore, we need to analyze the first two lines and get how to choose form the greatest
 * answer. We can analyze it by choosing one between the first line or the second line, and use a for loop
 * to determine the whole value for this rule. It is obvious that odd rows follow line 1, and even rows follow line 2.
 * After that, all we then need to do is to just get the maximum. However, what if you place two cows adjacent to each
 * other vertically? well, easy solution will just be to do the same thing again above and do it again vertically. Not
 * that it is not possible that one cow has two cows adjacent vertically and horizontal as that will make this sub
 * matrix have three cows.
 */

#include <iostream>
using namespace std;
const int N = 1e3 + 10;
int n, a[N][N];
int main() {
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int ans1 = 0;
    // analyze horizontally
    for(int j = 1;j<=n;j++){
        int odd = 0, even = 0;
        for(int i = 1;i<=n;i++){
            if(i % 2 == 0) even += a[i][j];
            else odd += a[i][j];
        }
        ans1 += max(odd, even);
    }
    int ans2 = 0;
    //analyze vertically
    for(int i = 1;i<=n;i++){
        int odd = 0, even = 0;
        for(int j = 1;j<=n;j++){
            if(j % 2 == 0) even += a[i][j];
            else odd += a[i][j];
        }
        ans2 += max(odd, even);
    }
    cout<<max(ans1, ans2)<<endl;
    return 0;
}
