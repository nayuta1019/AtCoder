/**
ABC073
2019/01/21/ 解説AC
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

int N, M, R;
int d[201][201];
int r[9];
int A, B, C;
int res;
bool used[9];

void dfs(int c, int las, int dist){
    if(c == R+1){
        if(res > dist) res = dist;
        return ;
    }
    for(int i = 1; i <= R; i++){
        if(!used[i]){
            used[i] = true;
            if(las == -1) dfs(c+1, i, 0);
            else dfs(c+1, i, dist+d[r[las]][r[i]]);
            used[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    scanf("%d%d%d", &N, &M, &R);
    for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) if(i != j) d[i][j] = INF;
    for(int i = 1; i <= R; i++) scanf("%d", &r[i]);
    for(int i = 1; i <= M; i++){
        scanf("%d%d%d", &A, &B, &C);
        if(d[A][B] > C) d[A][B] = d[B][A] = C;
    }
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(d[i][j] > d[i][k]+d[k][j]) d[i][j] = d[i][k]+d[k][j];
            }
        }
    }
    res = INF;
    dfs(1, -1, 0);
    printf("%d\n", res);

    return 0;
}