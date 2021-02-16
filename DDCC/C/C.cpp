/**
2018/11/23/ 解説AC
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

ll ppow(ll m, ll n) {
    if (n == 0) return 1;
    ll ret = ppow(m * m % MOD, n / 2);
    if (n % 2) ret *= m;
    return ret % MOD;
}

int main(){
	int N;
	cin >> N;

	ll ret = 0;
	for(int i = 1; i <= N; i++){
		ll w = ppow(i, 10) - ppow(i-1, 10);
		if(w < 0) w += MOD;
		ll u = ppow(N/i, 10);
		ret += w * u % MOD;
		if(ret >= MOD) ret -= MOD;
	}

	cout << ret << endl;

	return 0;
}