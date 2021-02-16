/**
2018/11/07/ 初見AC
累積和
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

ll Csum[110000];

int main(){
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);

    for(int i = 0; i < N; i++) cin >> a[i];

    for(int i = 1; i < N+1; i++){
        Csum[i] += a[i-1] + Csum[i-1];
    }

    ll sum = 0;
    for(int i = K; i < N+1; i++){
        sum += Csum[i] - Csum[i-K];
    }

    cout << sum << endl;

    return 0;
}