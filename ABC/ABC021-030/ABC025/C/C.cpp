/**
2018/11/23/ 未完成
方針が違う
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int b[2][3], c[3][2];

    rep(i, 2) rep(j, 3) cin >> b[i][j];

    rep(i, 3) rep(j, 2) cin >> c[i][j];

    int a = 4;
    cout << (a>>2 & 1) << endl;

    pair<int, int> ans;
    ans.first = 0;
    ans.second = 0;
    rep(bit, 1<<9){
        int cnt = 0, chokudai = 0, chokuko = 0;

        rep(i, 9) if(bit>>i & 1) cnt++;
        if(cnt != 4) continue;
        
        rep(i, 2){
            rep(j, 3){
                if( (bit>>(i*3+j) & 1) ^ (bit>>(i*3+j+3) & 1) ) chokuko += b[i][j];
                else chokudai += b[i][j];
            }
        }

        rep(i, 3){
            rep(j, 2){
                if( (bit>>(i*3+j) & 1) ^ (bit>>(i*3+j+1) & 1) ) chokuko += c[i][j];
                else chokudai += c[i][j];
            }
        }

        cout << "chokudai = " << chokudai << endl;
        cout << "chokuko = " << chokuko << endl;

        if(ans.second < chokuko){
            if(ans.first < chokudai){
                ans.first = chokudai;
                ans.second = chokuko;
            }
        }

    }

    cout << ans.first << endl;
    cout << ans.second << endl;

    return 0;
}