/**
2018/11/29/ 自力AC
問題文をしっかり読む。
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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    double total=0;
    int cnt=0;
    rep(i, N){
        if(A[i] == 0) continue;
        cnt++;
        total += A[i];
    }
    total /= cnt;
    total += 0.9;
    int ans = total;

    cout << ans << endl;

    return 0;
}