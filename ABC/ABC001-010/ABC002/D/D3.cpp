/**
ABC002
2019/03/22/ 自力AC
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

bool relation[12][12];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int N, M; cin >> N >> M;
    
    rep(i, M){
        int x, y;
        cin >> x >> y;
        x--; y--;
        relation[x][y] = relation[y][x] = true;
    }

    int ans = 0;
    for(int bit = 0; bit < 1<<N; bit++){
        int member[12] = {0};
        for(int i = 0; i < N; i++){
            if(bit>>i & 1){
                member[i] = 1;
            }
        }
        int cnt = 0;
        rep(i, N){
            if(member[i] == 0) continue;
            bool flag = true;
            rep(j, N){
                if(i == j) continue;
                if(member[j] == 0) continue;
                if(!relation[i][j]) flag = false;
            }
            if(flag) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}