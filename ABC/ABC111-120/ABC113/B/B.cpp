/**
2018/11/04/ 自力AC
キャストしっかりする。それか最初からdoubleにする！！！
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
 
int main(){
    ll N, T, A, H[1100];

    cin >> N >> T >> A;
    for(int i = 0; i < N; i++) cin >> H[i];

    double tmp = 1e9;
    ll ans = 0;
    for(int i = 0; i < N; i++){
        double t = (double)T - (double)H[i]*6/1000;

        if(abs(A-t) < tmp ){
            tmp = abs(A-t);
            ans = i;
        }
        
    }

    cout << ans + 1 << endl;

    return 0;
}