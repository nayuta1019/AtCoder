/**
KEYENCEPC2019
2019/01/13/ 自力AC
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

int memo[10];

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    memo[a] = 1;
    memo[b] = 1;
    memo[c] = 1;
    memo[d] = 1;
    if(memo[1] == 1 && memo[4] == 1 && memo[7] == 1 && memo[9] == 1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}