/**
ABC060
2019/01/09/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N, T;
    cin >> N >> T;
    vector<int> t(N);
    rep(i, N) cin >> t[i];

    ll x = 0;
    rep(i, N-1){
        if(t[i+1] < t[i] + T){
            x += t[i+1] - t[i];
        }else{
            x += T;
        }
    }
    x += T;

    cout << x << endl;

    return 0;
}