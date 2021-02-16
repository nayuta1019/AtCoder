/**
2018/11/10/ 初見AC
lower_bound()
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> a(N), b(M);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];

    int ans = 0, t = 0;
    while (1) {
        auto aitr = lower_bound(a.begin(), a.end(), t);
        if (aitr == a.end()) break;
        t = *aitr + X;
        auto bitr = lower_bound(b.begin(), b.end(), t);
        if (bitr == b.end()) break;
        t = *bitr + Y;
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}