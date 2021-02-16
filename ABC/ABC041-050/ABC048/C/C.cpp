/**
2018/11/12/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    ll cnt = 0;
    if(x < a[0]){
        cnt += a[0] - x;
        a[0] -= a[0] - x;
    }
    for(int i = 0; i < N-1; i++){
        if(x < a[i] + a[i+1]){
            ll tmp = abs(x - a[i] - a[i+1]);
            a[i+1] -= tmp;
            cnt += tmp;
        }
    }

    cout << cnt << endl;

    return 0;
}