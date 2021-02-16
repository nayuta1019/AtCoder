/**
ABC031
2018/12/31/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int L, H, N;
    cin >> L >> H >> N;
    rep(i, N){
        int A;
        cin >> A;
        if(H < A) cout << -1 << endl;
        else if(A < L) cout << L - A << endl;
        else cout << 0 << endl;
    }

    return 0;
}