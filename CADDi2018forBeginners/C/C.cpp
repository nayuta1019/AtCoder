/**
CADDi2018forBeginners
2018/12/22/ 未完成
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vector<int> > Mat;
typedef tuple<int, int, int, int> T;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};


//素因数分解
vector<long long> PrimeFactorize(long long n){
    vector<long long> primes(n);
    for (long long i = 2; i < n; ++i) primes[i] = 0;
    int ns = 2;   // 素因数

    //printf("%d:", n);
    while(ns <= sqrt(n)){
        while(n % ns == 0){ // 割り切れる間繰り返す
            n /= ns;
            primes[ns]++;
        }
        ns++;
    }
    if(2 < n) primes[n]++;
    
    return primes;
}

int main(){
    ll N, P;
    cin >> N >> P;

    vector<ll> v;
    v = PrimeFactorize(P);

    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}