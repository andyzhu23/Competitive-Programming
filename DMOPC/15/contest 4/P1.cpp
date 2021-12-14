#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Defines and one-liners
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
template <typename T> inline T& back(vector<T> &vec) { return *(vec.end() - 1); }
template <typename T> inline void pop(vector<T> &vec) { return vec.erase(vec.end() - 1); }

// Scan, Debug, and other nonsense
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> void printArray(ostream& out,T* arr,int sz){out<<"[";for(int i=0;i<sz;i++){out<<arr[i]<<", "; } out<<"]";}
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f,R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)

template <int MAX>
struct PrimeSieve {
    bool isPrime[MAX]; vector<int> primes;
    PrimeSieve() {}
    void calc() {
        memset(isPrime, true, sizeof isPrime);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < MAX; i++) {
            if (isPrime[i]) {
                for (int j = i + i; j < MAX; j += i)
                    isPrime[j] = false;
                primes.push_back(i);
            }
        }
    }
};

const int MAX = 148734 + 1;
int n, x;
PrimeSieve<MAX> pr;
ll tot = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(n, x);
    pr.calc();

    for (int prime : pr.primes) {
        if (prime > n)
            break;
        
        int sub = n - prime;

        tot += sub / x + 1;
        if (sub > 0)
            tot += (sub - 1) / x + 1;
    }

    cout << tot << "\n";

    return 0;
}
