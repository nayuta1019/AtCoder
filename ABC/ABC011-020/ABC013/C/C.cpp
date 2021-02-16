/**
2018/11/02/ 解説AC。100点解法
O(N^2)の計算量
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;


 
int main(){
    ll N, H, A, B, C, D, E;

    cin >> N >> H >> A >> B >> C >> D >> E;

    ll total = 0, ans = INT_MAX;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(0 < H + B*i + D*j - (N - i - j)*E ){
                total = i*A + j*C;
                ans = min(total, ans);
            }
        }
    }

    cout << ans << endl;


    return 0;
}