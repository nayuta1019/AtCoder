/**
ABC016
2018/12/21/ 解説AC
author:takeo1116
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

int main(){
    int Ax, Ay, Bx, By;
    int N;
    cin >> Ax >> Ay >> Bx >> By;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    int acro = 0;

    //すべての辺について、チョップと交差しているかどうかを調べる
	//交差している数を数える
	//符号付き面積を使う
    for(int i = 0; i < N; i++){
        int xa1 = Ax - X[i%N], ya1 = Ay - Y[i%N];
        int xa2 = Bx - X[i%N], ya2 = By - Y[i%N];
        int xb1 = Ax - X[(i+1)%N], yb1 = Ay - Y[(i+1)%N];
        int xb2 = Bx - X[(i+1)%N], yb2 = By - Y[(i+1)%N];
        ll A = xa1*ya2 - xa2*ya1;
        ll B = xb1*yb2 - xb2*yb1;
        ll C = xa1*yb1 - xb1*ya1;
        ll D = xa2*yb2 - xb2*ya2;
        if(A*B < 0 && C*D < 0) acro++;
    }

    cout << acro / 2 + 1 << endl;

    return 0;
}