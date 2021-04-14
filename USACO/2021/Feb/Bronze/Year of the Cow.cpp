#include <iostream>
#include <unordered_map>
#include <cmath>
#define int long long
using namespace std;
typedef pair<int, string> cow;
int n;
unordered_map<string, cow> Map;

string years[] = {"@" ,"Ox", "Tiger", "Rabbit", "Dragon",
                  "Snake", "Horse", "Goat", "Monkey",
                  "Rooster","Dog", "Pig", "Rat", "Ox",
                  "Tiger", "Rabbit", "Dragon", "Snake",
                  "Horse", "Goat", "Monkey", "Rooster",
                  "Dog", "Pig", "Rat"};

int getYear(string s, string c, cow b){
    if(s == "previous"){
        int pos;
        for(int i = 24; i > 12; i --){
            if(years[i] == b.second){
                pos = i;
            }
        }
        for(int i = pos - 1; i > 0;i --){
            if(years[i] == c){
                return pos - i;
            }
        }
    } else{
        int pos;
        for(int i = 1; i <= 12; i ++){
            if(years[i] == b.second){
                pos = i;
            }
        }
        for(int i = pos + 1; i <= 24;i ++){
            if(years[i] == c){
                return pos - i;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    Map["Bessie"] = make_pair(0, "Ox");
    for(int i = 1;i<=n;i++){
        string a, s, b, c;
        cin>>a>>s>>s>>s>>c>>b>>b>>b;
        Map[a].first = Map[b].first + getYear(s, c, Map[b]);
        Map[a].second = c;
    }
    cout<<abs(Map["Elsie"].first)<<endl;
    return 0;
}
