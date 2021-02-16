/**
2018/11/07/ 解説AC
しゃくとり法
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;
    vector<ll> s(N);
    for(int i = 0; i < N; i++) cin >> s[i];

    for(int i = 0; i < N; i++){
        if(s[i] == 0){
            cout << N << endl;
            return 0;
        }

    }

    ll res = 0;
    ll mul = 1;
    ll right = 0;
    for(ll left = 0; left < N; left++){

        while(mul * s[right] <= K && right < N){
            mul *= s[right];
            right++;
        }

        res = max(res, right-left);

        if(left == right) right++;
        else  mul /= s[left];
        
    }

    cout << res << endl;

    return 0;
}