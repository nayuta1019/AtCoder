/**
2018/11/22/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
	int N;
	cin >> N;
	vector<int> B(N + 1);

	for(int i = 2; i <= N; ++i) cin >> B[i];
	
	vector<pair<int, int>> memo(N + 1);

	for(int i = N; 1 <= i; i--){
		int c = B[i];
		int d = 1 + (memo[i].first > 0 ? memo[i].first + memo[i].second : 0);
		if(memo[c].first == 0){
			memo[c].first = memo[c].second = d;
		}else{
			memo[c].first = min(memo[c].first, d);
			memo[c].second = max(memo[c].second, d);
		}
	}

	cout << memo[0].first << endl;

	return 0;
}