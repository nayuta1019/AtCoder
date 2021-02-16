/**
2019/05/04/ 解説AC
author : square1001
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

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;
	map<int, int> A;
	rep(i, N){
		int x;
		cin >> x;
		A[x]++;
	}
	rep(_, Q){
		int L, R, X;
		cin >> L >> R >> X;
		int cnt = 0, ans = 0;
		auto it = A.lower_bound(L);
		while(it != A.end() && it->first <= R){
			if (it->second % 2 == 1) ans ^= it->first;
			cnt += it->second;
			it = A.erase(it);
		}
		A[X] += cnt;
		cout << ans << '\n';
	}
	
	return 0;
}