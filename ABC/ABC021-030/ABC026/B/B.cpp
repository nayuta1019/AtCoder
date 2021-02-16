/**
ABC026
2018/12/19/ 初見AC
大きい順にソートすれば場合分けしなくてもいい
**/
#define _USE_MATH_DEFINES
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
    vector<int> R(N);
    rep(i, N) cin >> R[i];

    sort(R.begin(), R.end(), greater<int>());

    double ans = 0;
    for(int i = 0; i < N; i+=2){
        ans += R[i]*R[i]*M_PI - R[i+1]*R[i+1]*M_PI;
    }

    printf("%.12f\n", ans);

    return 0;
}