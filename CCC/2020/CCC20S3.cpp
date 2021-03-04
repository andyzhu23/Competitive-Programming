#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 2e5 + 10;

int key[35];
int hay[N][34];
int len1,len2;
string n,h;
unordered_set<size_t> vis;
string sub;

bool isPerm(int i){
    int cur;
    int j = i + len1 - 1;
    for(int k = 1;k<=26;k++){
        cur = hay[j][k] - hay[i-1][k];
        if(cur != key[k]) return false;
    }
    return true;
}

int main() {
    cin>>n>>h;
    int ans = 0;
    len1 = n.size();
    len2 = h.size();
    for(int i = 1;i<=len1;i++){
        key[n[i-1] - 'a' + 1]++;
    }
    for(int i = 1;i<=len2;i++){
        for(int j = 1;j<=26;j++){
            hay[i][j] = hay[i-1][j];
        }
        hay[i][h[i-1] - 'a' + 1]++;
    }

    for(int i = 1;i<=len2 - len1 + 1;i++){
        if(isPerm(i)){
            sub = h.substr(i - 1, len1);
            hash<string> hasher;
            size_t hash = hasher(sub);
            if(!vis.count(hash)){
                ans++;
                vis.insert(hash);
            }
        }
    }
    cout<<ans;
    return 0;
}
