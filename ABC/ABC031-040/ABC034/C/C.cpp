/**
2018/11/07/ 自力100点解法
DPを使って計算
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

const ll MOD = 1000000007;

int main(){
    int W, H;
    
    cin >> W >> H;

    ll masu[H][W] = {0};

    for(int i = 1; i < W; i++) masu[0][i] = 1;
    for(int i = 1; i < H; i++) masu[i][0] = 1;

    for(int y = 1; y < H; y++){
        for(int x = 1; x < W; x++){
            masu[y][x] += (masu[y-1][x] + masu[y][x-1]) % MOD;
        }
    }

    cout << masu[H-1][W-1] << endl;

    return 0;
}