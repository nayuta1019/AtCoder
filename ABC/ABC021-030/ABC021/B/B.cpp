/**
ABC021
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
    int N, a, b, K;
    cin >> N >> a >> b >> K;
    vector<int> P(K);
    for(int i = 0; i < K; i++) cin >> P[i];

    vector<int> check(N+1, 0);
    bool flag = true;
    for(int i = 0; i < K; i++){
        if(P[i] == a) flag = false;
        if(P[i] == b) flag = false;
        if(check[P[i]] == 0) check[P[i]]++;
        else flag = false;
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}