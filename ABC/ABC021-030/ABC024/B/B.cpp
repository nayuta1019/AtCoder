/**
ABC024
2018/12/19/ 初見AC
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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int op = 0, cl = 0, ans = 0;
    rep(i, N){
        if(cl < A[i]){
            ans += cl - op;
            op = A[i];
            cl = A[i] + T;
        }else{
            cl = A[i] + T;
        }
    }
    ans += cl - op;
    cout << ans << endl;

    return 0;
}