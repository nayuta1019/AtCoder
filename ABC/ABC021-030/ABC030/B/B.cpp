/**
ABC030
2018/12/30/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    n = n%12;
    double s = (double)360/12*n+(double)360/12/60*m, l = (double)360/60*m;

    double ans = abs(l - s);
    if(180 <= ans) ans = 360 - ans;

    cout << ans << endl;

    return 0;
}