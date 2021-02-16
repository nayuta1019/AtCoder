/**
2018/11/20/ 自力AC
lower_bound(), upper_bound()
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll res = 0;
    for(int i = 0; i < N; i++){
        auto Iterup = lower_bound(ALL(A), B[i]);
        auto Iterdown = upper_bound(ALL(C), B[i]);
        res += (Iterup - A.begin())*(C.end() - Iterdown);
    }

    cout << res << endl;

    return 0;
}