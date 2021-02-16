/**
2019/04/21/ 解説用
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

    int N;
    string s;
    cin >> N >> s;

    vector<int> w(N+1, 0), b(N+1, 0);
    
    rep(i, N){
        w[i+1] += w[i] + (s[i] == '.' ? 1 : 0);
        b[i+1] += b[i] + (s[i] == '#' ? 1 : 0);
    }

    int ans = INF;
    rep(left, N+1){
        int sum = 0;

        sum += b[left] - b[0];//境界の左側を.にする数
        sum += w[N] - w[left];

        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}