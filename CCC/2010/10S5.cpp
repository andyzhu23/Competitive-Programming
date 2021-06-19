#include <bits/stdc++.h>
#define endl "\n"
#define lc (rt << 1)
#define rc (rt << 1 | 1)
#define ins insert
using namespace std;
const int N = 2100;
const int X = 2510;
stack<string> stk;
int x;
string input;
int dp[N][X];
int tree[N];
unordered_set<int> vis;

int ans = 0, g[N][X];

void dfs(int rt){
    if(tree[rt]){
        for(int i = 0;i<=x;i++){ // enumerate possible numbers of nutrients
            for(int j = 0;j<=min(720, i);j++){ // enumerate numbers of nutrients used for thickness
                int k = i - j; // numbers of nutrients used for production
                dp[rt][i] = max(dp[rt][i], min(int(pow(1 + j, 2)), k + tree[rt]));
            }
        }
        return;
    }
    dfs(lc);
    dfs(rc);
    for(int j = 0;j<=x;j++){
        for(int l = 0;l<=j;l++){
            int r = j - l;
            g[rt][j] = max(g[rt][j], dp[lc][l] + dp[rc][r]);
            if(rt == 1) ans = max(ans, g[1][j]);
        }
    }

    for(int j = 0;j<=x;j++){
        for(int w = 0;w<=min(j, 720);w++){
            dp[rt][j] = max(dp[rt][j], min(g[rt][j - w], (1 + w) * (1 + w)));
        }
    }
}

string getNext(int& i){
    string ans = "";
    while(input[i] != ' ') {
        if(input[i] == '(' || input[i] == ')') {
            if(ans == "") ans = input[i++];
            break;
        }
        ans += input[i++];
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c;
    getline(cin, input);
    if(input[0] != '(') {
        int k;
        cin>>k;
        cout<<stoi(input) + k<<endl;
        return 0;
    }
    stk.push("(");
    int rt = 1;
    int i = 1;
    // reading the tree
    while(!stk.empty()) {
        c = getNext(i);
        if(c == "") {i++; continue;}
        if(c == ")") {
            int r = stoi(stk.top()); stk.pop();
            int l = stoi(stk.top()); stk.pop();
            stk.pop();
            vis.ins(lc);
            vis.ins(rc);
            vis.ins(rt);
            tree[rc] = r;
            tree[lc] = l;
            if(!stk.empty()) stk.push("0");
            rt = rt >> 1;
        } else {
            if(c == "(") {
                if(stk.top() == "(") rt = lc;
                else rt = rc;
            }
            stk.push(c);
        }
    }
    cin>>x;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
