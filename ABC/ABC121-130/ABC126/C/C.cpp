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

int v[100005];

long long modpow(long long m, int n) {
    if (n == 0) return 1;
    long long ret = modpow(m * m % MOD, n / 2);
    if (n % 2) ret *= m;
    return ret % MOD;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        ll score = i;
        while(score < k){
            score *= 2;
            cnt++;
        }
        v[i] = cnt;
    }

    double ans = 0;
    for(int i = 1; i <= n; i++){
        double div = modpow(2, v[i]);
        ans += ( (double)1/(double)n ) * (double)1.0/div;
    }

    printf("%.12f\n", ans);
    return 0;
}