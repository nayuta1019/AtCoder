/**
ABC054
2019/01/02/ 自力AC
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

char A[51][51], B[51][51];

int main(){
    int N, M;
    cin >> N >> M;
    rep(i, N) rep(j, N) cin >> A[i][j];
    rep(i, M) rep(j, M) cin >> B[i][j];

    
    for(int i = 0; i < N-M+1; i++){
      for(int j = 0; j < N-M+1; j++){
        bool flag = true;
        for(int h = 0; h < M; h++){
          for(int w = 0; w < M; w++){
            if(A[i+h][j+w] != B[h][w]) flag = false;
          }
        }
        if(flag){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }

    cout << "No" << endl;

    return 0;
}