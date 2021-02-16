/**
2018/11/15/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    ll N, M;
    cin >> N >> M;

    ll ans = 0;

    if(2*N <= M){
        ans += N;
        M -= 2*N;
        ans += M / 4;
    }else{
        ans += M / 2;
    }

    cout << ans << endl;

    return 0;
}