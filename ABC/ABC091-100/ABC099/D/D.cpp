/**
2019/02/22/ 解説AC
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

int N, C;
int D[33][33], t[3][33];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    scanf("%d%d", &N, &C);
    rep(i, C) rep(j, C) scanf("%d", &D[i][j]);
    rep(i, N) rep(j, N){
        int x;
        scanf("%d", &x);
        t[(i+j)%3][x-1]++;
    }

    int res = 1<<30;
    rep(i, C) rep(j, C){
        if(i != j){
            rep(k, C){
                if(i != k && j != k){
                    int tt = 0;
                    rep(l, C) tt += D[l][i]*t[0][l];
                    rep(l, C) tt += D[l][j]*t[1][l];
                    rep(l, C) tt += D[l][k]*t[2][l];
                    if(tt < res) res = tt;
                }
            }
        }
    }

    printf("%d\n", res);

    return 0;
}