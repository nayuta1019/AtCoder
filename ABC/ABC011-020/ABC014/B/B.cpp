/**
2018/11/28/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int n, X;
    cin >> n >> X;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int res = 0;
    for(int bit = 0; bit < n; bit++){
        if(X>>bit & 1) res += a[bit];
    }

    cout << res << endl;

    return 0;
}