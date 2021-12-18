#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<long long,long long>

string f(string x, string y){
    string res="";
    for(int i=0; i<x.size(); i++){
        if(x[i]==y[i]) res+="0";
        else res+="1";
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r,l;
    cin>>r>>l;
    set<string> a,b;
    char c[r][l];
    for(int i=0; i<r; i++){
        for(int j=0; j<l; j++){
            cin>>c[i][j];
        }
    }
    string s[r];
    for(int i=0; i<r; i++){
        string temp="";
        for(int j=0; j<l; j++) temp+=c[i][j];
        s[i]=temp;
    }
    for(int i=0; i<r; i++){
        b.insert(s[i]);
        for(auto p:a){
            b.insert(f(p,s[i]));
        }
        a=b;
        b.clear();
    }
    cout<<a.size()<<'\n';
}
