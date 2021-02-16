/**
ABC067
2019/01/06/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    ll total = 0;
    rep(i, N){
        cin >> a[i];
        total += a[i];
    }

    ll left = 0, right = 0, ans = 1e12;
    rep(i, N-1){
        left += a[i];
        right = total - left;
        ans = min(ans, abs(left-right) );
    }

    cout << ans << endl;

    return 0;
}