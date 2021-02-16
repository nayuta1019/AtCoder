/**
ABC084
2019/02/12/ 解説AC
考察はあってた
エラトステネスの篩->累積和
prime[r] - prime[l-1]でいい
**/
#define _USE_MATH_DEFINES
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

vector<int> sieve_of_eratosthenes(int n) {
    vector<int> primes(n, 0);

    for (int i = 1; i < n; ++i) primes[i] = i;

    for (int i = 2; i*i < n; ++i){
        if (primes[i]){ //  0ならば素数ではない
            for (int j = i*i; j < n; j+=i) primes[j] = 0;   //  iの倍数を0にする
        }
    }

    //primes.erase(remove(all(primes), 0), primes.end());

    return primes;
}

int prime[100001];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int Q;
    cin >> Q;

    vector<int> p = sieve_of_eratosthenes(100001);
    for(int i = 3; i < 100001; i++){
        if(p[i] != 0 && p[(int) (p[i] + 1)/2 ] != 0) prime[i] = prime[i-1] + 1;
        else prime[i] = prime[i-1];
    }

    rep(i, Q){
        int l, r;
        cin >> l >> r;
        cout << prime[r] - prime[l-1] << endl;
    }

    return 0;
}