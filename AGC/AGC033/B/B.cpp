/**
AGC033
2019/05/05/ 未完成
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

    int H, W, N, sr, sc;
    string S, T;
    cin >> H >> W >> N >> sr >> sc;
    sr--; sc--;
    cin >> S >> T;

	int lx = sr, ly = sr, rx = sr, ry = sr;

	rep(i, N){
		if(S[i] == 'U') --lx;
		if(S[i] == 'D') ++rx;
		if(S[i] == 'L') --ly;
		if(S[i] == 'R') ++ry;

		if(lx < 0 || rx >= H || ly < 0 || ry >= W){
			cout << "NO" << endl;
            return 0;
		}
		if(T[i] == 'U' && rx >= 1) --rx;
		if(T[i] == 'D' && lx <= H - 2) ++lx;
		if(T[i] == 'L' && ry >= 1) --ry;
		if(T[i] == 'R' && ly <= W - 2) ++ly;
	}

    cout << "YES" << endl;

    return 0;
}