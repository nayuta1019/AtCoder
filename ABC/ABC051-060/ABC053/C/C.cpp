/**
ABC053
2019/01/17/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    ll x;
    cin >> x;

    
    ll ans = (x / 11) * 2;
    if(0 < x % 11 && x % 11 <= 6) ans += 1;
    else if(7 <= x % 11) ans += 2;

    cout << ans << endl;

    return 0;
}